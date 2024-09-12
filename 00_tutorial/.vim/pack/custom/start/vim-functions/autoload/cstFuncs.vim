"==================================================
" Functions
"==================================================
function! cstFuncs#FontSizeMod(addNum)
	let l:gf_size_whole = matchstr(&guifont, '\( \)\@<=\d\+$')
	let l:gf_size_whole = l:gf_size_whole + a:addNum
	let l:new_font_size = ' '.l:gf_size_whole
	let &guifont = substitute(&guifont, ' \d\+$', l:new_font_size, '')
endfunction

function! cstFuncs#FontChange()
	set guifont=*
endfunc

function! cstFuncs#LineSpace(addNum)
	let &linespace = &linespace + a:addNum
endfunction

function! cstFuncs#CMDHeight(addNum)
	let &cmdheight = &cmdheight + a:addNum
endfunction

function! cstFuncs#ToggleRelativeNumber()
	if(&relativenumber == 1)
		set norelativenumber
		set number
	else
		set relativenumber
	endif
endfunc

function! cstFuncs#ToggleCursorLine()
	set cursorline!
endfunc

function! cstFuncs#ToggleListChars()
	set list!
endfunc

function! cstFuncs#ToggleWrap()
	set wrap!
endfunc

function! cstFuncs#ToggleGUIMenu()
	if(matchstr(&guioptions, 'm') == 'm')
		set guioptions-=m
	else
		set guioptions+=m
	endif
endfunc

