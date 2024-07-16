#pragma once

#include <iostream>
#include "../mensajes.pb.h"
#include <memory>

class ConexionBuilder
{
public:
    ConexionBuilder() : message_(new mensaje::conexion()) {}

    ConexionBuilder &set_estado(bool estado)
    {
        message_->set_estado(estado);
        return *this;
    }

    std::unique_ptr<mensaje::conexion> build()
    {
        auto built_message = std::move(message_);
        reset(); // Reiniciar el estado del builder
        return built_message;
    }

private:
    void reset()
    {
        message_ = std::unique_ptr<mensaje::conexion>(new mensaje::conexion());
    }

    std::unique_ptr<mensaje::conexion> message_;
};

class BusquedaBuilder
{
public:
    BusquedaBuilder() : message_(new mensaje::Busqueda()) {}

    BusquedaBuilder &set_texto(const std::string &texto)
    {
        message_->set_texto(texto);
        return *this;
    }

    std::unique_ptr<mensaje::Busqueda> build()
    {
        auto built_message = std::move(message_);
        reset(); // Reiniciar el estado del builder
        return built_message;
    }

private:
    void reset()
    {
        message_ = std::unique_ptr<mensaje::Busqueda>(new mensaje::Busqueda());
    }

    std::unique_ptr<mensaje::Busqueda> message_;
};

class PeliculaBuilder
{
public:
    PeliculaBuilder() : message_(new mensaje::Pelicula()) {}

    PeliculaBuilder &set_titulo(const std::string &titulo)
    {
        message_->set_titulo(titulo);
        return *this;
    }

    PeliculaBuilder &set_tag(const std::string &tag)
    {
        message_->set_tag(tag);
        return *this;
    }

    PeliculaBuilder &set_sinopsis(const std::string &sinopsis)
    {
        message_->set_sinopsis(sinopsis);
        return *this;
    }

    std::unique_ptr<mensaje::Pelicula> build()
    {
        auto built_message = std::move(message_);
        reset(); // Reiniciar el estado del builder
        return built_message;
    }

private:
    void reset()
    {
        message_ = std::unique_ptr<mensaje::Pelicula>(new mensaje::Pelicula());
    }

    std::unique_ptr<mensaje::Pelicula> message_;
};

class ResultadoBusquedaBuilder
{
public:
    ResultadoBusquedaBuilder() : message_(new mensaje::Resultado_Busqueda()) {}

    ResultadoBusquedaBuilder &add_pelicula(const mensaje::Pelicula &pelicula)
    {
        *message_->add_peliculas() = pelicula;
        return *this;
    }

    std::unique_ptr<mensaje::Resultado_Busqueda> build()
    {
        auto built_message = std::move(message_);
        reset(); // Reiniciar el estado del builder
        return built_message;
    }

private:
    void reset()
    {
        message_ = std::unique_ptr<mensaje::Resultado_Busqueda>(new mensaje::Resultado_Busqueda());
    }

    std::unique_ptr<mensaje::Resultado_Busqueda> message_;
};
