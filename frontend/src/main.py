import mensajes_pb2

# Crear un mensaje
busqueda = mensajes_pb2.Busqueda(texto="hola")

print(type(busqueda))
# Serializar el mensaje
serialized = busqueda.SerializeToString()
print(serialized)

# Deserializar el mensaje
new_busqueda = mensajes_pb2.Busqueda()
new_busqueda.ParseFromString(serialized)
print(new_busqueda)
