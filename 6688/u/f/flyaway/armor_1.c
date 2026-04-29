#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name(HIC"轩辕神铠"NOR,({ "xuanyuan shenkai", "armor","shenkai"}));
        set("long","一件"+HIC"轩辕神铠"NOR+"。armor 100，armor_vs_force 200，装备等级：一级。\n");
        set("min_level",1);
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 20000);
                set("material", "goldsilk");
                set("armor_prop/armor", 100);
                set("armor_prop/armor_vs_force", 200);
        }    
        setup();
}
/*Z3A41EEC3D44C762590617584E80E4E635297E3B8H*/

