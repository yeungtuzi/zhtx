
inherit ROOM;

void create()
{
        set("short", "秘道");
        set("long", @LONG
这是一条幽暗的甬道，甬道两旁嵌有铜灯。甬道斜斜地伸如地下，不知
有多长，也不知伸向何处，两壁铜灯上却没有什么灰尘。
LONG
        );
        set("exits", ([ 
	  "east" : __DIR__"secretpath1",
	  "up"   : __DIR__"jmqshenmu",
	]));

        setup();
        replace_program(ROOM);
}

