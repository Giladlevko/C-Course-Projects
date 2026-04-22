call plug#begin()

Plug 'neoclide/coc.nvim', {'branch': 'release'}

call plug#end()
set mouse=a
inoremap <expr> <Tab> coc#pum#visible() ? coc#pum#confirm() : "\<Tab>"

