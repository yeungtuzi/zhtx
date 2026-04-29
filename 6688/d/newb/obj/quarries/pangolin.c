///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"穿山甲"NOR, ({"pangolin","chuan shan jia","jia"}));
        set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("value", 3000);
                set("long",
@LONG
哺乳纲，鳞甲目，穿山甲科。体和尾被有角质鳞。头小，吻尖，
口、耳和眼都小，无齿，舌细长，能从口孔伸出舔取食物。四肢短；
爪强壮锐利。栖于丘陵杂树林潮湿地带。主食蚁类及白蚁。产于天朝
长江以南地区至台湾；越南、缅甸、尼泊尔等地亦产。为官府二级保护动物。
LONG);
                set("dex",30);
                set("mark_hunt",1);
        }
        set("unpawnable",1);
        setup();
}

