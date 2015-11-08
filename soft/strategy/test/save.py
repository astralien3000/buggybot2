import bpy

def get_leg_loc(leg):
    tar = bpy.data.objects['Leg.'+leg+'.Target']
    ret = [
        tar.location[0],
        tar.location[1],
        tar.location[2],
    ]
    return ret

sce = bpy.data.scenes[0]

anim = []
for i in range(sce.frame_start, sce.frame_end+1):
    sce.frame_set(i)
    frame = {
        'LF' : get_leg_loc('LF'),
        'RF' : get_leg_loc('RF'),
        'RB' : get_leg_loc('RB'),
        'LB' : get_leg_loc('LB'),
    }
    anim.append(frame)
    
f = open('mod/anim.py', 'w')

f.write('# ANIMATION\n')
f.write('\n')
f.write('anim = ')
f.write(str(anim))
f.write('\n')
