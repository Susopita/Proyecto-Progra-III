from clientSocket import ClientSocket # type: ignore
from socket import AF_INET, SOCK_STREAM
import flet as ft

IP = '127.0.0.1'
PUERTO = 8080
FAMILIA_SC = AF_INET # Dominio: IPv4 
TIPO_SC = SOCK_STREAM

"""
Comando de ejecucion:
python tests/comunicacion_b-f/test_frontend.py
"""

# Conexion con backend
client_socket = ClientSocket(
    IP=IP,
    PUERTO=PUERTO,
    FAMILY_SC=FAMILIA_SC,
    TIPO_SC=TIPO_SC
)

def main(page: ft.Page):

    # Busquedas
    titulos: list = []

    # Función para manejar el clic en el botón de búsqueda
    def show_search_field(e):
        search_field.visible = True
        page.update()
        search_field.focus()

    # Función para manejar el envío de información
    def handle_search():
        search_term = search_field.value
        dialog_busqueda.value = f"Buscando: {search_term}"
        dialog_busqueda.update()
        dialog_content.controls.clear()
        for i in titulos:
            dialog_content.controls.append(ft.Text(i))
        dialog_content.update()
        dialog.open = True
        search_field.visible = False
        search_field.value = ""
        page.update()

    # Función para cerrar el diálogo
    def close_dialog(e):
        dialog.open = False
        page.update()

    def solicitar_busqueda(e: ft.ControlEvent):
        print("enviando confirmacion")
        client_socket.enviar_estado(True)
        print("Enviando solicitud de busqueda")
        client_socket.enviar_solicitud_busqueda(e.data)
        print("Esperando resultados")
        result = client_socket.recibir_resultados_busqueda()
        print("resultados obtenidos:")
        titulos.clear()  # Limpiar los títulos anteriores
        for i in result:
            titulos.append(f"{i['titulo']}")
        print(f"Títulos actualizados: {titulos}")  # Verificar la actualización de los títulos
        page.update()

    # Configuracion de App
    # Título de la app
    page.title = "Vimex"

    # Color de fondo de la app
    page.bgcolor = ft.colors.WHITE

    # Crear informacion extra
    dialog_busqueda = ft.Text(value="")

    # Crear el contenido del diálogo
    dialog_content = ft.ListView(height=350, auto_scroll=True)

    # Crear el campo de texto y ocultarlo inicialmente
    search_field = ft.TextField(
        visible=False, 
        autofocus=True, 
        on_change=lambda e: solicitar_busqueda(e),
        on_submit=lambda e: handle_search(), 
        text_style=ft.TextStyle(color=ft.colors.BLACK))

    # Crear el diálogo
    dialog = ft.AlertDialog(
        title=ft.Text("Resultado de la búsqueda"),
        content=ft.Column(controls=[dialog_busqueda, dialog_content]),
        actions=[ft.TextButton("OK", on_click=close_dialog)],
        bgcolor=ft.colors.BLUE
    )

    # Crear el botón de búsqueda con forma de lupa
    search_button = ft.IconButton(icon=ft.icons.SEARCH, on_click=show_search_field, icon_color=ft.colors.BLACK)
    
    # Agregar el botón y el campo de texto a la página
    page.add(ft.Row([search_button, search_field]))

    # Añadir el diálogo a la página
    page.overlay.append(dialog)

with client_socket as cliente:
    if cliente.confirmacion_backend():
        ft.app(target=main)
        cliente.enviar_estado(False)
    else:
        print("Error al iniciar conexion")