" Specify the plugin manager (vim-plug)
call plug#begin('~/.vim/plugged')

" Add the vim-cpp-enhanced-highlight plugin
Plug 'octol/vim-cpp-enhanced-highlight'

" End plugin definitions
call plug#end()

" Enable highlighting of class scope
let g:cpp_class_scope_highlight = 1

" Enable highlighting of member variables
let g:cpp_member_variable_highlight = 1

" Enable highlighting of class names in declarations
let g:cpp_class_decl_highlight = 1

" Enable highlighting of POSIX functions
let g:cpp_posix_standard = 1

" Highlight template functions (choose one)
" Option 1: Works in most cases, but can be slow on large files
let g:cpp_experimental_simple_template_highlight = 1
" Option 2: Faster implementation but may have corner cases where it doesn't work
" let g:cpp_experimental_template_highlight = 1

" Enable highlighting of library concepts
let g:cpp_concepts_highlight = 1

" Disable highlighting of user-defined functions
" Uncomment the line below if you want to disable function highlighting
" let g:cpp_no_function_highlight = 1

