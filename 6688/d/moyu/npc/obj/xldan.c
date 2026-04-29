// xl_dan.c 雪狼内丹
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT"雪狼内丹"NOR, ({ "xuelang dan", "dan" }));
        set_weight(60);
        set("unit", "颗");
        set("long", "一颗雪狼内丹，是修道人的练气宝物。\n");
        set("value", 50000);
      	set("unpawnable", 1);
      	set("nature",([
      		"yinyang":-40000,
      		]));
}
