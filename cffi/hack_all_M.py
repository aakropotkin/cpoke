# This file provides a process for making all.E
# 1) make cffi/data/all.M
# 2) python hack_all_M.py
# 3) copy the result into Makefile in place of the ORDERED_E defintion.
# 4) rm -f cffi/data/all.E; make cffi/data/all.E

from matplotlib import pyplot as plt
import networkx as nx
import pdb

def read_file(fname):
    with open(fname, 'rt') as f:
        return f.read()

raw = read_file('cffi/data/all.M')
lines = raw.replace('\\\n', ' ').replace('  ', ' ').replace('  ', ' ').split('\n')
lines = [x.strip() for x in lines]
lines = [x for x in lines if x != '']


def strip_prefix(s, prefix):
    if s.startswith(prefix):
        return s[len(prefix):]
    return s

def strip_origin(s):
    s = strip_prefix(s, 'src/')
    s = strip_prefix(s, 'include/')
    return s

def strip_suffix(s, suffix):
    if s.endswith(suffix):
        return s[:-len(suffix)]
    return s

def strip_ext(s):
    s = strip_suffix(s, '.h')
    s = strip_suffix(s, '.o')
    s = strip_suffix(s, '.c')
    return s

#def do_strip(s):
#    return strip_ext(strip_origin(s))


do_strip = strip_origin
accum = {}
keepable = set()
for line in lines:
    # print(line)
    left, right = line.split(': ')
    right = right.split(' ')
    left = do_strip(left)
    right = [do_strip(r) for r in right]
    for r in right:
        if r.endswith('.h') and not '..' in r:
            keepable.add(strip_ext(r))
    accum[left] = right

accum2 = {}
for l in accum.keys():
    ll = strip_ext(l)
    found = False
    for k in keepable:
        if k.endswith(ll):
            print(f'found: {k}, {ll}')
            if found:
                print('found twice?!')
            found = True
            accum2[k] = [strip_ext(r) for r in accum[l] if r.endswith('.h') and not r.startswith('/')]
            accum2[k] = [r for r in accum2[k] if r != k]

g = nx.DiGraph(accum2)

print('=========cycles before:')
for x in nx.algorithms.cycles.simple_cycles(g):
    print(x)

#['parse_gm', 'gm_store']
#['player', 'pokemon', 'battle']
#['player', 'battle']
#['battle', 'pokemon']

g.remove_edges_from([('battle', 'pokemon'), ('battle', 'player'), ('parse_gm', 'gm_store')])

print('=========cycles after:')
count = 0
for x in nx.algorithms.cycles.simple_cycles(g):
    print(x)
    count += 1
assert count == 0, 'remove more edges'

print('=========result:')
accum = []
for name in nx.lexicographical_topological_sort(g):
    accum.append(name)
    # print(name)

#print(accum[::-1])
if False:
    nx.draw(g, with_labels=True, font_weight='bold')
    plt.show()

accum2 = [f'cffi/data/{x}.E' for x in accum[::-1] if not '..' in x and not x.startswith('defs/')]
print('ORDERED_E = ' + ' '.join(accum2))

# pdb.set_trace()

