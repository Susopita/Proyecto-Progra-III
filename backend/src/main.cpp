#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "backend/include/search_algorithm.hpp" // Incluir el header del archivo de búsqueda
                                                /*
                                                struct Pelicula
                                                {
                                                    std::string titulo;
                                                    std::string tag;
                                                    std::string sinopsis;
                                                };
                                                
                                                // Función para cargar la base de datos desde un archivo CSV
                                                std::vector<Pelicula> cargarBaseDeDatos(const std::string &nombreArchivo)
                                                {
                                                    std::vector<Pelicula> peliculas;
                                                
                                                    std::ifstream archivo(nombreArchivo);
                                                    if (!archivo.is_open())
                                                    {
                                                        std::cerr << "Error al abrir el archivo." << std::endl;
                                                        return peliculas;
                                                    }
                                                
                                                    std::string linea;
                                                    while (std::getline(archivo, linea))
                                                    {
                                                        std::stringstream ss(linea);
                                                        std::string titulo, tag, sinopsis;
                                                        if (std::getline(ss, titulo, ',') &&
                                                            std::getline(ss, tag, ',') &&
                                                            std::getline(ss, sinopsis, ','))
                                                        {
                                                            peliculas.push_back({titulo, tag, sinopsis});
                                                        }
                                                    }
                                                
                                                    archivo.close();
                                                    return peliculas;
                                                }
                                                
                                                // Función para buscar una película por título
                                                Pelicula *buscarPeliculaPorTitulo(const std::vector<Pelicula> &peliculas, const std::string &tituloBuscado)
                                                {
                                                    for (Pelicula &pelicula : peliculas)
                                                    {
                                                        if (pelicula.titulo == tituloBuscado)
                                                        {
                                                            return &pelicula;
                                                        }
                                                    }
                                                    return nullptr;
                                                }
                                                
                                                // Función para buscar películas por tag
                                                void buscarPorTag(const std::vector<Pelicula> &peliculas, const std::string &tagBuscado)
                                                {
                                                    bool encontrada = false;
                                                    for (const Pelicula &pelicula : peliculas)
                                                    {
                                                        if (pelicula.tag == tagBuscado)
                                                        {
                                                            std::cout << "Título: " << pelicula.titulo << std::endl;
                                                            std::cout << "Tag: " << pelicula.tag << std::endl;
                                                            std::cout << "Sinopsis: " << pelicula.sinopsis << std::endl;
                                                            std::cout << std::endl;
                                                            encontrada = true;
                                                        }
                                                    }
                                                    if (!encontrada)
                                                    {
                                                        std::cout << "No se encontraron películas con ese tag." << std::endl;
                                                    }
                                                }
                                                
                                                // Función para mostrar la sinopsis de una película y las opciones de "Me gusta" y "Ver más tarde"
                                                void mostrarSinopsis(Pelicula *pelicula)
                                                {
                                                    if (pelicula)
                                                    {
                                                        std::cout << "Título: " << pelicula->titulo << std::endl;
                                                        std::cout << "Tag: " << pelicula->tag << std::endl;
                                                        std::cout << "Sinopsis: " << pelicula->sinopsis << std::endl;
                                                        std::cout << std::endl;
                                                    }
                                                    else
                                                    {
                                                        std::cout << "No se encontró la película." << std::endl;
                                                    }
                                                }
                                                
                                                // Función para mostrar las películas añadidas en "Ver más tarde"
                                                void mostrarPeliculasVerMasTarde(const std::vector<std::string> &verMasTarde, const std::vector<Pelicula> &peliculas)
                                                {
                                                    if (verMasTarde.empty())
                                                    {
                                                        std::cout << "No tienes películas guardadas para ver más tarde." << std::endl;
                                                    }
                                                    else
                                                    {
                                                        std::cout << "Películas guardadas para ver más tarde:" << std::endl;
                                                        for (const std::string &titulo : verMasTarde)
                                                        {
                                                            Pelicula *pelicula = buscarPeliculaPorTitulo(peliculas, titulo);
                                                            if (pelicula)
                                                            {
                                                                std::cout << "Título: " << pelicula->titulo << std::endl;
                                                                std::cout << "Tag: " << pelicula->tag << std::endl;
                                                                std::cout << "Sinopsis: " << pelicula->sinopsis << std::endl;
                                                                std::cout << std::endl;
                                                            }
                                                        }
                                                    }
                                                }
                                                
                                                // Función para mostrar películas similares a las que el usuario le ha dado "Me gusta"
                                                void mostrarPeliculasSimilares(const std::vector<std::string> &peliculasGustadas, const std::vector<Pelicula> &peliculas)
                                                {
                                                    if (peliculasGustadas.empty())
                                                    {
                                                        std::cout << "No has dado 'Me gusta' a ninguna película todavía." << std::endl;
                                                    }
                                                    else
                                                    {
                                                        std::cout << "Películas similares a las que te han gustado:" << std::endl;
                                                        for (const std::string &titulo : peliculasGustadas)
                                                        {
                                                            Pelicula *pelicula = buscarPeliculaPorTitulo(peliculas, titulo);
                                                            if (pelicula)
                                                            {
                                                                std::cout << "Título: " << pelicula->titulo << std::endl;
                                                                std::cout << "Tag: " << pelicula->tag << std::endl;
                                                                std::cout << "Sinopsis: " << pelicula->sinopsis << std::endl;
                                                                std::cout << std::endl;
                                                            }
                                                        }
                                                    }
                                                }
                                                
                                                int main()
                                                {
                                                    // Cargar la base de datos desde el archivo CSV
                                                    std::vector<Pelicula> peliculas = cargarBaseDeDatos("base_de_datos.csv");
                                                
                                                    // Vectores para almacenar películas guardadas para ver más tarde y películas que le gustan al usuario
                                                    std::vector<std::string> verMasTarde;
                                                    std::vector<std::string> peliculasGustadas;
                                                
                                                    // Ejemplo de búsqueda por título
                                                    std::string tituloBuscado;
                                                    std::cout << "Ingrese el título de la película que desea buscar: ";
                                                    std::getline(std::cin, tituloBuscado);
                                                    Pelicula *pelicula = buscarPeliculaPorTitulo(peliculas, tituloBuscado);
                                                    mostrarSinopsis(pelicula);
                                                
                                                    // Ejemplo de búsqueda por tag
                                                    std::string tagBuscado;
                                                    std::cout << "Ingrese el tag de la película que desea buscar: ";
                                                    std::getline(std::cin, tagBuscado);
                                                    buscarPorTag(peliculas, tagBuscado);
                                                
                                                    // Mostrar las películas añadidas en "Ver más tarde"
                                                    mostrarPeliculasVerMasTarde(verMasTarde, peliculas);
                                                
                                                    // Mostrar películas similares a las que el usuario le ha dado "Me gusta"
                                                    mostrarPeliculasSimilares(peliculasGustadas, peliculas);
                                                
                                                    // Ejemplo de búsqueda similar con concurrencia
                                                    std::string frase;
                                                    std::cout << "Ingrese la frase de búsqueda: ";
                                                    std::getline(std::cin, frase);
                                                
                                                    // Buscar películas/series similares
                                                    std::vector<Pelicula> resultados = buscarPeliculas(peliculas, frase);
                                                
                                                    // Mostrar resultados
                                                    std::cout << "Resultados encontrados:\n";
                                                    for (const Pelicula &pelicula : resultados)
                                                    {
                                                        std::cout << "Título: " << pelicula.titulo << std::endl;
                                                        std::cout << "Tag: " << pelicula.tag << std::endl;
                                                        std::cout << "Sinopsis: " << pelicula.sinopsis << std::endl;
                                                        std::cout << std::endl;
                                                    }
                                                
                                                    return 0;
                                                }
                                                */