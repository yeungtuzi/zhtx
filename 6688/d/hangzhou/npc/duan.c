//by tlang
//97.12
//duan.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIM"段玉"NOR, ({"duan yu", "duan"}) );
	set("long", "他穿着鲜明的绸衫，很轻，很薄，剪裁得很合身，脚上穿着\n"
"特地从关外买来的小牛皮软马靴，手上拿着温州“皮硝李”精制的乌梢马鞭，把手\n"
"上还镶着颗比龙眼还大三分的明珠。\n");
	set("per", 30);
	set("int", 40);
	set("str", 30);
	set("gender", "男性");
	set("age", 19);
	set("combat_exp", 500000);
	set("max_force", 1500);
	set("force", 1500);
	set("force_factor", 100);
	
	set_skill("dodge", 100);
	set_skill("cuff", 100);
	set_skill("parry", 100);
	set_skill("blade", 100); 
	set_skill("force", 100);
	set_skill("jingang-quan", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("cibei-dao", 100);
	set_skill("xiaoyaoyou", 100);
	map_skill("blade", "cibei-dao");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "hunyuan-yiqi");
	map_skill("cuff", "jingang-quan");

	add_money("gold", 2);
	setup();
	carry_object("/d/hangzhou/npc/obj/bydao")->wield();
	carry_object("/d/suzhou/npc/obj/cloth2")->wear();
}

void init()
{
	add_action("do_talk", "talk");
}

int do_talk(string arg)
{
	object me, ob, obj;
	me=this_player();
	
	if(!me->query("combat_exp")>=500000 || arg!="duan yu")
		return notify_fail("段玉仿佛没听见你的话，不理你。\n");
	if(me->query("marks/save_duan")>=3 )
	{
		command("bow "+me->query("id"));
		command("whisper "+me->query("id")+" 前几次多蒙老兄相救，但你是不是也该适可而止呢？\n");
			return 1;
	}
	me->set("mark/begin",1);
	tell_object(me, "你上前想和段玉说几句话，正在这时候，湖面上忽然有艘\n"
"快艇，箭一样破水而来。快艇上站着几个健壮的和尚，只听得砰的一声，那艘快艇\n"
"笔直地向画舫撞了上去。丽人被撞得几乎跌了下去。几个和尚跳了上去，指着她破\n"
"口大骂,有一个甚至伸出蒲扇般的手，仿佛要抓她的头发。段玉抓起桌上的刀，霍\n"
"然一长身,就已经窜出了栏杆。栏杆外就是一片湖水，眼看他就要掉在水里，只见他\n"
"矫健地在围鱼的栏杆上一点，人又腾空而起，然后在空中凌空一翻身，一式“细胸巧\n"
"翻云”，跟着一式“平沙落雁”，轻巧地落在画舫上。\n"); 
	ob=this_object();	
	destruct(ob);
		return 1;
}