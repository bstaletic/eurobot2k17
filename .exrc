set ts=4 sts=4 sw=4
let g:ycm_confirm_extra_conf = 0
inoremap <F8> <C-o>:make<CR>
nnoremap <F8> :make<CR>

" Neomake - run the maker with :Neomake gcc
let g:neomake_c_gcc_maker={
	\ 'exe': 'arm-none-eabi-gcc',
	\ 'args': [ '-Os', '-g', '-Wall', '-Wextra', '-Wno-main', '-pedantic', '-x', 'c', '-std=c99', '-DSTM32F4', '-DSTM32F407VG', '-DSTM32F4CCM', '-I.', '-Ilibopencm3/include', '-c', ],
	\ 'errorformat': '%f:%l:%c: %m', }
