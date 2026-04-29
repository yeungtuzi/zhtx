inherit ROOM;

void create()
{
        set("short", "擂台");
	set("long", @LONG
  这是一个方形的比武擂台,正有两人在台上打的难分难解,
边上有几个人在主持比武大会,并不时支支点点，台下是一溜
看台，不时地传出助威呐喊声。
LONG
        );
        set("exits", ([
	  "out" : __DIR__"sheshen",
	]));
	
	set("objects",([
		__DIR__"npc/gongpz" : 1,
	]));

	set("watch_room",({
		__DIR__"kantai0",
		__DIR__"kantai1",
		__DIR__"kantai2",
		__DIR__"kantai3",
		__DIR__"kantai4",
		__DIR__"kantai5",
		__DIR__"kantai6",
		__DIR__"kantai7",
		__DIR__"kantai8",
		__DIR__"kantai9",
	}));

        set("no_clean_up", 0);
        set("outdoors", "xx" );
        set("no_death",1);
        set("no_fight",1);

        setup();
        replace_program(ROOM);
}
