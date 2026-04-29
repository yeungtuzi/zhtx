//darkwood7.c
//by zephyr

#include "ansi.h"

inherit "/u/z/zephyr/sunflower/sfroom";

void create()
{
	set("short", "暗黑森林");
	set("long", BLK@LONG
你无法相信自己的耳朵了，你居然听到周围有个声音，
哦不，是几个声音合在一起，在哼着一首你从未听过的乐
曲。那声音时而远在天边，偶尔又象就在你耳边响起，另你
开始感觉有些晕眩了……心里仿佛有个声音在说留在这里吧！
永远留在这里…………你头皮发麻，周围一定有什么不对劲
的东西，看来得赶快离开这里了。
可是那音乐缠绕着你，你头脑发昏，根本分不清楚哪是东南
西北………………

LONG NOR);

	set("objects", ([
		__DIR__"npc/gaoda.c" : 1,

	]));

	
	setup();

}

void reset()
{
        ::reset();
        set("exits", ([ 
          "south" : __DIR__"darkwood" + (random(3)+8),
          "east" : __DIR__"darkwood" + (random(3)+8),
          "west" : __DIR__"darkwood" + (random(3)+8),
          "north" : __DIR__"darkwood8",
          "southeast" : __DIR__"darkwood1",
          "southwest" : __DIR__"darkwood" + (random(3)+8),
          "northwest" : __DIR__"darkwood" + (random(3)+8),
          "northeast" : __DIR__"darkwood" + (random(3)+8),
        ]));
}
int valid_leave(object me, string dir)
{
        write(BLU"幽冥鬼乐让你分不清楚方向，四周全都是树...."NOR);
        switch(dir) {
                case "north":   write(CYN"你摇摇晃晃地往北边的树林钻去...."NOR);    break;
                case "east":    write(CYN"你摇摇晃晃地往东边的树林钻去...."NOR);      break;
                case "south":   write(CYN"你摇摇晃晃地往南边的树林钻去...."NOR);      break;
                case "west":    write(CYN"你摇摇晃晃地往西边的树林钻去...."NOR);        break;
                case "northeast":    write(CYN"你摇摇晃晃地往东北边的树林钻去...."NOR);        break;
                case "northwest":    write(CYN"你摇摇晃晃地往西北边的树林钻去...."NOR);        break;
                case "southeast":    write(CYN"你摇摇晃晃地往东南的树林钻去...."NOR);        break;
                case "southwest":    write(CYN"你摇摇晃晃地往西南的树林钻去...."NOR);        break;
                default:
                        write("该往哪里走呢....");
        }
        write("周围全是树...\n");
        return 1;
}
#include "/u/z/zephyr/sunflower/npc/robroom.h"
