// sanbaduanji.c
//by masterall

#include <weapon.h>
#include <ansi.h> 
inherit HALBERD;

void create()
{
        set_name(HIM"三八"+HIW"短戟"NOR, ({ "sanba duanji","duanji","ji"}) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", @long
    这长三尺八寸的精钢短戟，据说是庞斑早年间使用的兵刃，后来传给了其弟子方夜羽
，确是戟中的神品。它是用北海海底据说来自天上的神秘“玄铁”所制，不但炼制时的火
温要比一般精铁高上数倍，熔铸出来后的玄铁，也比一般精铁重上数倍，所以别小看这支
短戟，竟有一百五十七斤之重。 
long
);
                set("value", 0);
                set("material", "steel");
                set("rigidity", 200000);
                set("wield_msg", "$n"+HIC"离土而出，顿时在空中幻出万道青芒，\n蓦然往$N身前回收，变回从容握在右手烁光流闪的三尺八寸短戟！！\n"NOR);
                set("unwield_msg", "青芒一闪，$N手中的$n鬼魅般地消失了。\n");
                set("weapon_prop/attack", 20); 
                set("weapon_prop/dodge", 20); 
                set("weapon_prop/parry", 20);
                set("weapon_prop/defense", 10);
                set("weapon_prop/speed", 20);
                set("weapon_prop/courage", 20); 
                set("weapon_prop/personality", 20);
                set("weapon_prop/composure", 20);
                set("weapon_prop/spirituality", 20); 
        }
        init_halberd(150,EDGED | SECONDARY);      
        setup();
}

