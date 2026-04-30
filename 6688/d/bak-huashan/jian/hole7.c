// hole.c

inherit ROOM;
void create()
{
         string *hole=({
                                 __DIR__"hole0",
                                 __DIR__"hole1",
                                 __DIR__"hole2",
                                 __DIR__"hole3",
                                 __DIR__"hole4",
                                 __DIR__"hole5",
                                 __DIR__"hole6",
                                 __DIR__"hole7",
                        });

        int i;

        i=random(257);

        set("short", "神秘洞窟");
        set("long", @LONG
这是一个神秘的树洞，树洞向四周不断伸展着，你不知道它
究竟一直通向何方。这里耸立着一扇大铁门，但是上面用铁锁牢
牢地锁着。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
              "east" : hole[(i+0)%8],
         "southeast" : hole[(i+1)%8],
             "south" : hole[(i+2)%8],
         "southwest" : hole[(i+3)%8],
              "west" : hole[(i+4)%8],
         "northwest" : hole[(i+5)%8],
             "north" : hole[(i+6)%8],
         "northeast" : hole[(i+7)%8],
        ]));

        setup();
        replace_program(ROOM);
}
int valid_leave(object me,string arg)
{
	int j;
	// 2026-04-30: unused variable commented out
	// object weapon,ob1,ob2;
	if (!present("gold key",this_player())||!present("secret map",this_player()))
	{
		message_vision("你手中没有钥匙无法打开大门，没有地图没法进一步探险。\n");
		return 0;
	}
	j=me->query_temp("dir_wrong");
	j++;
	me->set_temp("dir_wrong",j);
	if (random(j))
	{
		message_vision("你忽然感到一阵天旋地转，你又被送回来开始的地方。");
		me->move(__DIR__"zhongting");
        	me->delete_temp("dir_wrong");
	}
	else {
		message_vision("你感觉一阵腾云驾雾，就来到了一个陌生的地方。\n");
		me->move(__DIR__"cliff");
		}
}