// Room: /d/xingxiu/droom.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "丁春秋卧室");
	set("long", @LONG
这里就是丁老怪的起居之室，屋内仅一床一桌,陈设极为简陋，并无什么起眼之处。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room2",
]));
	set("no_clean_up", 0);
	set("no_quit", 1);
	set("fake_ding", 1);

	setup();
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg)
{
	object *obs, ob;

	ob = this_player();

	obs = all_inventory(environment(ob));
	if( sizeof(obs) > 1 )
		return notify_fail("还是等没旁人的时候再找吧！\n");

	if( ob->is_busy() )
		 return notify_fail("你正忙着了。\n");

	if(!arg || arg=="")
		return notify_fail("你要搜什么？\n");
	if(arg =="desk" || arg == "桌子" || arg == "书桌"){
		if( ob->query("mark/ding_chushi") != 3)
			return notify_fail("你什么也没有搜到！\n");
		ob->start_busy(1);
		message_vision("$N从书桌里搜出一封书信！！！", ob);
		tell_object(ob, "你看到信封上写着苏星河门主谨启几字，你想起穿云子临终前的话，嗤的一声把封口撕开了，你见到上面写着：\n");
		tell_object(ob, HIY"星河老贼：\n余居星宿二十载有三，几已翻遍整海，何有半本本派秘籍！\n老贼听着：“限你在一月之内交出本派秘藉北冥神功，否则函谷八小贼绝难活命！”\n另：江湖有言无崖子老贼未死，速从实相告，如有半句隐瞒，逍遥派鸡犬不留！\n\n                春秋于二月初九\n\n\n"NOR);
		tell_object(ob, "看来穿云子所说不假！！！\n");
		ob->start_busy(10);
		ob->delete("env/no_get");
		tell_object(ob, "便在此时，你听到屋外乱成一遍，看来事情败露，得想办法逃跑！\n");
		ob->delete("family/master_id");
		ob->delete("family/master_name");
		ob->set("family/title", "弃徒");
		ob->set("title", "星宿派弃徒");
		ob->add("betrayer", 1);
		ob->set("faith", -300);
		ob->set("mark/ding_chushi", 4);
		call_out("do_flee_xingxiu", 2, ob);
		return 1;
	}
	if( (arg != "床") && (arg != "bed") )	
		return notify_fail("这里没有"+arg+"！\n");
	if( environment(ob)->query("fake_ding") ){
		environment(ob)->delete("fake_ding");
		message_vision("$N从床上搜到一个神木王鼎。\n", ob);
		ob->set_temp("wangding", 1);
		new(__DIR__"obj/fake_ding")->move(ob);
		return 1;
	}
	else
		return notify_fail("你什么也没有搜到！\n");
}

void do_flee_xingxiu(object me)
{
	object ob;
	
	message_vision("\n\n\n星宿老仙，德配天地，威振寰宇，古今无比！\n", me);
	message_vision("我看这小贼当日入门就不怀好意，不想今日果然所料不错！\n", me);
	message_vision("跳梁小丑，还不快快束手就擒！我们老仙一向慈悲为怀，或可饶你一命！\n", me);
	message_vision("。。。。。。\n\n", me);

	message_vision("$N眼见情势危急，一弯身往床底下钻去。\n", me);
	ob = new(__DIR__"npc/tianlang");
	ob->move(environment(me));
	ob->kill_ob(me);
	message_vision("$n冒冒失失冲了进来，$N出手入风，已拿住$n的要穴！", me, ob);	
	tell_object(me, "你脑海如电火石光般地一闪，已然有了计策！\n");
	message_vision("$N提起$n的硕大身躯往窗户外扔去，只听得外面一阵乱叫，小贼跳窗想逃，快堵主后门。\n", me, ob);
	ob->move(__DIR__"houshan3");
	ob->unconscious();
	tell_object(me, "你乘此机会，一口气冲出星宿海，额头汗水涔涔落下！\n");
	me->set("mark/ding_chushi", 5);
	me->set("mark/waiting_ding", me->query("mud_age"));
	me->move(__DIR__"xxh1");
	tell_object(me, HIG"你终于逃出了丁春秋的魔掌，可是以后到哪里安身立命呢？\n正派人士固然认定你是邪门歪道，而邪派如丁春秋之流已令人难以启齿，又岂能再入魔窟！\n其时明月中天，清风拂体，你只觉得天下虽大，竟无一处容身之处！\n"NOR);
	return;
}

int valid_leave(object me, string dir)
{
	if( me->query("mark/ding_chushi") > 3 ){
		return notify_fail("跑不了啦！\n");
	}
	return ::valid_leave(me, dir);
}
