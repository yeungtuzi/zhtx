//NPC:/d/xueshan/npc/goldend.c 
//by tlang for 旋芒宝剑
         
#include <ansi.h>

#ifndef SWORDDATA
#define SWORDDATA "/data/weapon/hsword/sword/"
#endif

inherit NPC;

void do_check();
void checking();
int do_pray();

void create()
{
	set_name(YEL"五爪金龙"NOR, ({ "golden dragon", "dragon"}));
	set("race", "野兽");
	set("age", 98);
	set("gender", "雄性");
	set("long", "一头张牙舞爪的龙，看上去不好惹。\n");
	set("attitude", "peacefully");

	set("limbs", ({ "头部", "身体", "尾巴","前脚", "後脚"}) );
        set("verbs", ({ "bite","claw" }) );

	set("str", 40);
	set("dex", 40);

	set("max_kee",3000);
	set("max_gin",1500);
	set("max_sen",1500);

	set("combat_exp", 3000000);
	set("shen_type", 0);

	set_skill("unarmed", 150);
	set_skill("dodge", 200);
	set_skill("parry", 200);

	set("no_get",1);
	setup();
	call_out("do_check",5);
}

void init()
{
	object ob;

	::init();
        if( interactive(ob = this_player()) ) {
	remove_call_out("greeting");
	call_out("greeting",1,ob);
	}
	add_action("do_pray","pray");
}

void greeting(object ob)
{
	
	if(!environment() || environment(ob)!=environment()
|| !environment(ob)->query("hidden_place") )
		return;
	command("say 你能来到这儿，也算不容易了。祈祷吧，孩子！幸运将会降临到你头上。");
	ob->start_busy(2);
}

int do_pray()
{
	object ob,obj,what;
	string newfile,filename,id;
	
	ob=this_player();
	id=ob->query("id");
	
	if(!environment() || environment(ob)!=environment()
|| !environment(ob)->query("hidden_place") )
		return notify_fail("你这是干什么？\n");
	if( objectp( what=present("lighting sword",ob) ) )
		return notify_fail("你已经得到过一把旋芒宝剑了，太贪心了吧？\n");
	newfile = read_file("/d/xueshan/npc/obj/xsword.c");
	newfile = replace_string( newfile, "no_owner", id);
	filename = SWORDDATA+id+".c";
	if(!write_file(filename, newfile,1))
		return notify_fail("你没有写入这个文件的权力。\n");
	command("smile");
	message_vision(YEL"$N虔诚地跪下祈祷。。。。。。。。。。\n"NOR+
	HIW"只见金龙把嘴张开，一把光芒四射的宝剑从它口中跃进$N的手掌。\n"NOR,ob);
	ob->start_busy(2);
//	ob->set("own_xsword",1);
	set("xsword_gone",1);
	obj = new(filename);
	obj->move(ob);
	ob->delete("can_pass1");
	ob->delete("can_pass2");
	command("whisper "+ob->query("id")+" "+HIM"有了这把剑，再找齐邪剑穿灵，寒于宝衣.\n"NOR+
	HIM"拿着这三件宝贝到杭州找小霖，可以合成一把混世神剑。自己努力吧！\n"NOR);
		return 1;
}

void do_check()
{
	message("system",
		HIR "\n你听到天空中传来一阵可怕的咆哮 ....\n\n"
		YEL	"五爪金龙" HIR "用震耳欲聋的声音吼道：\n\n"
			"\t\t嗷嗷嗷嗷嗷！！！！！！！！！！ ！\n\n" NOR,users() );
	call_out("checking",5);
}

void checking()
{
	if(!environment() || environment(this_player())!=environment() )
	{
		call_out("do_check",120);
		return;
	}
	if(!query("xsword_gone") )
	{
		call_out("checking",60);
		return;
	}
	message("sys",HIW"金龙发出欢快的叫声，驾云而去。\n"NOR,users() );
	destruct(this_object());
}

