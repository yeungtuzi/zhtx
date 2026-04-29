// /d/xizang/class/bad/enter.c

inherit ROOM;

void create()
{
        set("short", "谷内");
	set("long", @LONG
这里是恶人谷内,一条长长的石板街往东延伸,西边是出谷的方向.两旁野花盛
开,一股芬芳扑鼻而来.
LONG
);
	set("item_desc", ([
		"flower" : "一朵看上去很美丽的野花,你好想把它摘(pick)下来\n",
		  "野花" : "一朵看上去很美丽的野花,你好想把它摘(pick)下来\n",
		    "花" : "一朵看上去很美丽的野花,你好想把它摘(pick)下来\n",
	]));

	set("exits", ([
		 "west" : __DIR__"gate",
		 "east" : __DIR__"road1",
	]));
	set("outdoors", "xizang");
	setup();
}

void init()
{
	remove_action("do_pick", "pick");
	add_action("do_pick", "pick");
}

int do_pick(string arg)
{
	object me, ob;
	int i, j, k;
	if (!arg || (arg=="")) return notify_fail("你要摘什么?\n");
	if (arg=="flowers") return notify_fail("你太贪心了,一次只能摘一朵!\n");
	if ((arg=="flower") || (arg=="野花") || (arg=="花")) {
		me = this_player();
		i = me->query("cps");
		if (random(i) > 11) return 
	notify_fail("你想了想,觉得恶人谷里的东西还是少碰为好,收回了手.\n");
	message_vision("$N经不住花香的诱惑,摘下了一朵野花!\n", me);
	j = me->query("kar");
	if (random(j) < 19) {
	message_vision("$N被花茎上的刺刺了一下,但是竟然不觉得疼痛!\n", me);
		k = me->query("con");
		k = 30 - k;
		if (k < 3) k = 3;
		// at least 3 poison condition
		i = me->query_condition("noname");
		me->apply_condition("noname", i + k);
		}
	ob = new(OBJ_DIR"toy/noname");
	ob->move(me);
	return 1;
	}
	return notify_fail("这里没有" + arg +"\n");
}
