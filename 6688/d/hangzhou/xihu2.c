//xihu2c
//by dwolf

#include <ansi.h>
inherit ROOM;

string* objects = ({
	"heye",
	"hehua",
	"lianp",
});

void create()
{      
	int i= random(sizeof(objects));
	set("short", GRN"西湖美景"NOR);
	set("long", @LONG
	  古人道：上有天堂，下有苏杭，而杭州最美处莫过于西湖，可见
西湖在世人眼中有多美，你在船上只见轻舟往来，笑声萧声，还有采莲姑娘
们的歌声，同着荷花香荷叶香，还有水香，简直让你醉了。
LONG
	);    
	set("exits", ([
		"southeast" : __DIR__"xihu3", 
		"north" : __DIR__"xihu1",
	]));
	set("objects", ([
	__DIR__"npc/obj/"+objects[i] : 2
	]));

	setup();
}
