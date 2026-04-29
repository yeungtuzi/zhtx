///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIB"巨松鼠"NOR, ({"squirrel","black giant squirrel","songsu"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("value", 6000);
                set("long",
@LONG
生活于热带雨林、季雨林。用前肢和嘴取食。喜食果实、嫩叶、花蕊。
体长40厘米，尾长50～60厘米。体重1000～3000克。是严格的树栖啮齿类动
物，在白天单独或成对活动，动作灵活，生性机警。每年9～10月发情，来年
5～6月产仔。属哺乳纲啮齿目松鼠科。分布于云南南部、广西、海南。
官府II级重点保护动物。
LONG);
                set("dex",60);
                set("mark_hunt",1);
        }
        set("unpawnable",1);
        setup();
}

