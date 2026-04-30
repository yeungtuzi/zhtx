// /d/xizang/npc/obj/tent.c
// 野营帐篷
// by mscat

inherit ITEM;

void create()
{
	set("short", "野营帐篷(tent)");
	set("long", "你在一座狭小的野营帐篷内,几乎无法转身.\n");
	set_name("帐篷", ({ "tent", "zhang peng"}));
	set_weight(6000);
	set_max_encumbrance(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long", @LONG
    这是一顶精工缝制的野营帐篷,收起来(pack)时很小可以随身携带,展
开架好(deploy)后则可容纳一到两个人,是野外冒险者的理想装备之一.
LONG
);
		set("value", 10000);
	}
}

int is_container() { return 1; }

void init()
{
	add_action("do_deploy", "deploy");
}

int do_deploy(string arg)
{
	object ob, me;
	string by_whom;
	if(!arg || (arg!="帐篷" && arg!="tent"))
		return notify_fail("你要架设什么?\n");
	me=this_player();
	ob=this_object();
	if(environment(ob)==me) ob->move(environment(me));
	if(environment(ob)!=environment(me))
		return notify_fail("你不知怎么搞的,就是无法架好帐篷!\n");
	if(!environment(ob)->query("outdoors")) {
		ob->move(me);
		return notify_fail("你不是想在别人家里扎营吧?\n");
	}

	if(stringp(by_whom=ob->query("deploied"))) {
		add_action("do_enter", "enter");
		return notify_fail("帐篷已经架设好了.\n");
	}

	ob->set("deploied", me->query("id"));
	ob->set("capacity", 2);
	ob->set_max_encumbrance(500000000); //half of a room
	ob->set("no_get", 1);
	ob->set("no_get_from", 1);

	message_vision("$N三两下支好了帐篷,可以进去(enter)休息了.\n", me);
	add_action("do_enter", "enter");
	add_action("do_pack", "pack");
	return 1;
}

int do_pack(string arg)
{
	string by_whom;
	object ob;

	if(!arg || (arg!="tent" && arg!="帐篷"))
		return notify_fail("你要收拾什么?\n");
	ob=this_object();
	if(stringp(by_whom=ob->query("deploied"))) {
		if((int)ob->query("capacity")!=2 )
			return notify_fail("帐篷里好象还有人,暂时不能收!\n");
		ob->delete("deploied");
		ob->set_max_encumbrance(1);
		ob->delete("no_get");
		ob->delete("no_get_from");
		ob->move(this_player());
		message_vision("$N把帐篷小心收折好.\n", this_player());
		return 1;
	}
	return notify_fail("帐篷没有支开,不需要收拾.\n");
}

int do_enter(string arg)
{
	object me, ob;
	if(!arg|| (arg!="帐篷" && arg!="tent"))
		return notify_fail("你要钻进哪里去?\n");
	me=this_player();
	ob=this_object();
	if(environment(me)==ob)
		return notify_fail("你已经在帐篷里面了.\n");

	if(!ob->query("capacity"))
		return notify_fail("帐篷里已有两个人了,你再也无法挤进去.\n");
	ob->add("capacity", -1);
	me->move(ob);
	add_action("do_sleep", "sleep");
	add_action("do_out", "out");
	return 1;
}

int do_sleep(string arg)
{
	object bag, me;
	// 2026-04-30: unused variable commented out
	// int time;
	if(arg && arg !="") return notify_fail("睡觉就睡觉,罗嗦什么啊!\n");
	me=this_player();
	if(environment(me)!=this_object())
		return notify_fail("要睡就钻进(enter)帐篷里来睡啊!\n");

	if(me->query_condition("sleep"))
	return notify_fail("你刚在五分钟内睡过一觉, 多睡对身体有害无益! \n");
	if(objectp(bag=present("sleeping bag", me))){
		message_vision("$N打开睡袋,钻了进去.\n", me);
		bag->move(environment(me));
		bag->set("unpacked", 1);
		bag->set_max_encumbrance(100000000);
		bag->set("no_get", 1);
		bag->set("no_get_from", 1);
		me->move(bag);
	} else {
	message_vision("$N不管三七二十一,往地上一躺...\n", me);
	if(random(me->query_con()+me->query_kar()) <10 )
		me->apply_condition("ganmao", 1+random(11));
	}
	message_vision("很快就睡着了.\n", me);
	me->set_temp("block_msg/all",1);
	me->apply_condition("sleep", 10);
	me->disable_player("<睡梦中>");
	call_out("wakeup", random(45 - me->query("con")) + 1, me,
		environment(me)); 
	return 1;
}

void wakeup(object me, object where)
{
                object * inv;
                int i;

	me->set("kee", me->query("eff_kee"));
	me->set("gin", me->query("eff_gin"));
	me->set("sen", me->query("eff_sen"));
	if( (me->query("max_force")/2 - me->query("force")/2) > 0 )
	me->add("force", me->query("max_force")/2 - me->query("force")/2 );
	me->enable_player();
	me->set_temp("block_msg/all", 0);
	message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。\n",me);
	/*  call move to re init all actions dao 971216 */
	if(where->query("id")=="sleeping bag") {
	        me->move(environment(where));
		where->delete("unpacked");
		where->set_max_encumbrance(1);
		message_vision("$N从睡袋里钻了出来,顺便收起了睡袋.\n", me);
		where->delete("no_get");
		where->delete("no_get_from");
		where->move(me);
	}
        inv = all_inventory(me);
                i = sizeof(inv);
                while(i--) {
                        string status=inv[i]->query("equipped") ;
                        inv[i]->move(me);
                        if( status == "worn" ) inv[i]->wear();
//                        else if (status == "wielded") inv[i]->wield();
                }
	remove_action("do_out", "out");
	add_action("do_out", "out");
}

int do_out(string arg)
{
	object ob;
	ob=environment(this_player());
	if (ob->query("id")!="tent")
		return notify_fail("你无处可去\n");
	this_player()->move(environment(ob));
	message_vision("$N钻出帐篷\n", this_player());
	ob->add("capacity", 1);
	add_action("do_pack", "pack");
	add_action("do_enter", "enter");
	return 1;
}
