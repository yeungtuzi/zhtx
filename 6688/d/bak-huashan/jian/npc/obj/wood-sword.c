//木剑
//wood-sword.c
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
   set_name("木剑",({"mu jian","jian","sword"}));
   set("weight",1000);
              
   if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
              set("value",1);
              set("long","这是一把普普通通的木剑。从上到下没什么特异之处。");
             }
    init_sword(15);
    setup();
}
