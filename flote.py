import flet as ft

def main(page: ft.Page):
    # Inicializar una lista vacía para almacenar los títulos de las búsquedas
    titulos = []

    # Función para manejar el clic en el botón de búsqueda
    def show_search_field(e):
        search_field.visible = True
        page.update()
        search_field.focus()

    # Función para manejar el envío de información
    def handle_search(e):
        search_term = search_field.value
        dialog_content.value = f"Buscando: {search_term}\n" + "\n".join(titulos)  # Actualizar el contenido del diálogo
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
        titulos.clear()  # Limpiar los títulos anteriores
        titulos.append("Titulo: hola\nTags: Hola Tags")
        print(f"Títulos actualizados: {titulos}")  # Verificar la actualización de los títulos
        page.update()

    # Configuracion de App
    # Título de la app
    page.title = "Vimex"

    # Color de fondo de la app
    page.bgcolor = ft.colors.WHITE

    # Crear el contenido del diálogo
    dialog_content = ft.Text(value="")

    # Crear el campo de texto y ocultarlo inicialmente
    search_field = ft.TextField(
        visible=False, 
        autofocus=True, 
        on_change=solicitar_busqueda,
        on_submit=handle_search, 
        text_style=ft.TextStyle(color=ft.colors.BLACK))

    # Crear el diálogo
    dialog = ft.AlertDialog(
        title=ft.Text("Resultado de la búsqueda"),
        content=ft.Column(controls=[dialog_content]),
        actions=[ft.TextButton("OK", on_click=close_dialog)],
        bgcolor=ft.colors.BLUE
    )

    # Crear el botón de búsqueda con forma de lupa
    search_button = ft.IconButton(icon=ft.icons.SEARCH, on_click=show_search_field, icon_color=ft.colors.BLACK)
    
    # Agregar el botón y el campo de texto a la página
    page.add(ft.Row([search_button, search_field]))

    # Añadir el diálogo a la página
    page.overlay.append(dialog)

# Iniciar la aplicación
ft.app(target=main)
