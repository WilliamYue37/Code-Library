import os

out = open('/Users/williamyue/.vim/UltiSnips/cpp.snippets', 'w')
for f in os.listdir('../Sublime Snippets'):
    subl = open('../Sublime Snippets/' + f, 'r')
    snip, trigger, descrip, flag  = '', '', '', False
    for line in subl:
        if ']]></content>' in line: flag = False
        if flag:
            snip += line
        if '<content><![CDATA[' in line: flag = True

        if '<tabTrigger>' in line: trigger = line.split('tabTrigger')[1][1:-2]
        if '<description>' in line: descrip = line.split('description')[1][1:-2]
    out.write('snippet ' + trigger + ' \"' + descrip + '\"\n' + snip + 'endsnippet\n\n')
