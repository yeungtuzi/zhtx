
inherit ROOM;

void create()
{
        set("short", "翠竹林");
        set("long", @LONG
这里已靠近竹林的边缘，一条小溪哗啦啦欢跃著，冲向竹林，但一靠近竹
林，小溪就安静了下来。透过竹林的缝隙，你可以看见一些高大挺拔的松树，
隐约可见一些红瓦白墙，飞檐楼阁。
LONG
        );
        set("exits", ([ 
  		"west" : __DIR__"jmqshulin1",
	  	"north" : __DIR__"bamboo2",
		"enter" : __DIR__"jmqdating",
	]));
        set("outdoors", "mingjiao");
        
        setup();
        
	replace_program(ROOM);
}

