#include <weapon.h>
#include <ansi.h>
inherit HOOK;
void create()
{
    set_name("判官笔",({"panguan bi","bi","pen"}));
    set_weight(10000);
    if( clonep() )
         set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 1);
                set("material", "steel");
                set("rigidity",500000);
                set("long", @LONG
一杆精钢所铸的判官笔，长一尺六寸，奇怪的是，判官笔笔
头上竟然缚有一束沾过墨的羊毛，恰如是一枝写字用的大笔。
LONG);
                
        }
        init_hook(40);
        setup();

}