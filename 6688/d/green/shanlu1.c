//write by lysh
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "山间小路");
        set("long", @LONG
这是一条笔直的，由晶莹的白石铺成的道路。路旁是两行修剪整齐的
花草，微风吹过，花香袭人。白色的晶石在天光下闪著迷人的色彩。一切
显的是那样的宁静，可你的内心却有一种不祥的预感。
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"shangukou",
  "west":__DIR__"field1",

]));
        
        set("outdoors", "jitang");
        setup();
        replace_program(ROOM);

}
