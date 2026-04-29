//xihu4.c
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
们的歌声，同着荷花香荷叶香，还有水香，简直让你醉了。但这美丽下面似
乎隐藏着什么不祥。脚下一处荷叶散开，似乎可以潜水(dive)下去，但下面
黑漆漆的，让人看了害怕。
LONG
	);    
	set("exits", ([
		"southup" : __DIR__"h_styy4", 
		"north" : __DIR__"xihu5",
	]));
	set("objects", ([
	__DIR__"npc/obj/"+objects[i] : 2,
	]));

	setup();
}

void init()
{
	add_action("do_dive","dive");
}

int do_dive()
{
	object me=this_player();

	if(!me->query("marks/killer") || me->query("test4"))
		return notify_fail("下面据说有恶龙，你还是别下去的好。\n");
	message_vision("$N一个猛子扎了下去。\n",me);
	me->move("/d/hangzhou/hole");
		return 1;
}	

int valid_leave(object ob,string dir)
{
	if(dir=="southup")
	{
		tell_object(ob,HIC"你弃舟登上了三潭映月岛。\n"NOR);
		return 1;
	}
	return 1;
}