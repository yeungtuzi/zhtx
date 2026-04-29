// Room: /d/hua/road2.c

inherit ROOM;

int do_fishing(object me);

void create()
{
	set("short", "河边");
	set("long", @LONG
到这里路断了。面前是一条水流湍急的大河。
一块大石头(stone)伸向河中，旁边还放着几根钓鱼(fish)杆。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road1",
]));
	set("item_desc", ([
		"stone" : "禁止游泳(swim)!!! 有生命危险!!! \n",
		"石头" : "禁止游泳(swim)!!! 有生命危险!!! \n",
		"大石头" : "禁止游泳(swim)!!! 有生命危险!!! \n",
		]));

	setup();
}

void init()
{
	add_action("no_quit", "quit");
	add_action("do_swim", "swim");
	add_action("do_fish", "fish");
}

int no_quit()
{
        object me;
        me = this_player();
        if (me->query("marks/点菜")) {
                message_vision("$N刚想溜之大吉，但一想到还欠一屁股债就留下了。\n", me);
                return 1;
        }
        return 0;
}

int do_swim()
{
	object me;
	me = this_player();
	message_vision("$N不顾危险跳入水中，向对岸游去…\n", me);
	me->move(__DIR__"river");
	return 1;
}

int do_fish()
{
	object me, fish;

	me = this_player();
        if(me->query("sen")<11)
          return notify_fail("你的精神不能集中,钓鱼可不是那么容易的事\n");
	message_vision("$N拿起一根钓鱼杆坐在大石头上钓起鱼来……\n", me);
        me->add("sen",-10);
        me->start_busy(2);
        call_out("do_fishing",2,me);
        return 1;
}

int do_fishing(object me)
{
        object fish;
        int kar, cps;

	message_vision("$N只见鱼漂猛然一动，急忙提杆…\n",me);
	kar = me->query("kar");
	cps = me->query("cps");

        if (random(kar+cps)>((kar+cps)/10)*9) {
                message_vision("$N钓到一条金鲤鱼\n", me);
                fish = new(__DIR__"obj/gfish");
                fish->move(me);
		return 1;
        }
	if (random(kar+cps)>((kar+cps)/3)*2) {
		message_vision("$N钓到一条大鲤鱼\n", me);
		fish = new(__DIR__"obj/fish");
		fish->move(me);
	}
	else{
		message_vision("$N什么也没钓到。\n",me );
            }
	return 1;
}
