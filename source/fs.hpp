#pragma once

#include <iostream>
#include <vector>

namespace oni
{
    class fs
    {
    public:
        class path_t
        {
        public:
            enum types
            {
                file,
                directory
            };
        
            path_t(const char * path): path_t(std::string(path)){}
            path_t(std::string path):
                updated(false)
            {change_path(path);}
            path_t(const path_t &path);

            bool is_directory() {return type == types::directory;}
            types get_type() {return type;}
            std::string get_path() {return path;}
            std::string get_extension() {return extension;}
            std::string get_relative_name() {return name;}

            void change_path(std::string path);

            void update();
            void update(std::string path)
            {change_path(path); update();}

            bool is_updated() {return updated;}
        private:
            std::string path;
            std::string name;
            std::string extension;
            size_t size;
            types type;
            
            bool updated = false;
        };
        
        typedef std::vector<path_t> paths_t;
        
        static paths_t get_subpaths(std::string path);
        static paths_t get_subpaths_recursively(std::string path);
        static std::string get_extension(std::string path);
        static std::string get_relative_name(std::string path);

    private:
        static const char path_div_character;
        static const char ext_character;
    };
}