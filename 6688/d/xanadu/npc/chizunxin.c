#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
	object sword;

	set_name("赤尊信", ({ "chi zunxin","chi","zunxin"}) );
	set("long",@LONG
	赤尊信是马贼起家，凶残暴烈，早名震西陲。此人身形雄伟之极，脸的下
半部长满了针剌般的短髭，连棱角分明的厚唇也差点遮盖了，一对眼铜铃般大，闪
闪生威，顾盼间自有一股慑人气态
LONG
	 );

	set("title",RED"盗霸"NOR);
	set("max_gin", 1000);
	set("max_kee", 3000);                    
	set("max_sen", 1000);
	set("max_force",5000); 
	set("force",10000);
	set("force_factor",250);     
	set("combat_exp",69999999);
	set("cor",100);
	set("cps",100);
	set("age",35);

	set_skill("cloudstaff", 220);
	set_skill("dodge", 220);
	set_skill("mysterrier",220);
	set_skill("parry", 220); 
	set_skill("iron-cloth",220);
	set_skill("jin-gang",220);
	set_skill("staff",220);
	set_skill("force",220);
	set_skill("celestial",220);
        set_skill("wuxinglun",220);
        set_skill("mo-chui-jue",220);

	map_skill("force","celestial");
        map_skill("hammer","wuxinglun");
	map_skill("staff","cloudstaff");
	map_skill("parry","cloudstaff");
	map_skill("dodge","mysterrier");
	map_skill("move","mysterrier");
	map_skill("iron-cloth","jin-gang");

//	prepare_skill("claw","spicyclaw");
	set_temp("apply/damage",150);
/*
	set("chat_chance",3);
        set("chat_msg_combat", ({
		"浪翻云凝视着窗外的明月，姿态悠闲之极。\n",
		"浪翻云举起盛满了清溪流泉的酒壶喝了一大口，笑道：痛快，痛快！\n"
        }) );
*/
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
		(: exert_function,"powerup" :),
                (: perform_action,"hammer.wuxing" :),
        }) );

	setup();

        carry_object("/d/heimuya/obj/coolhammer")->wield();
        add_money("tenthousand-cash",1);
        if(random(10)>2) carry_rnd_equip(3,5);		
}                          

int init()
{
        set("shen",-500000);
	return 1;
}
                             
int killed_enemy(object ob)
{
	command("sigh");
}
