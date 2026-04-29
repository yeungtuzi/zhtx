//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t,i;
	set("level",5);
	set_name("管懋", ({ "guan mao","guan"}) );
	set("long",MAG@LONG
管懋是天下第一精明之人，且爱武成痴，几乎走遍天下各门各派。他
使了什么手段使得各门派肯传授他武功始终是个谜，世人只知他所学
颇为驳杂，道家、佛家、魔几道武功他几乎样样射猎，虽然并非样样
精通，却也颇有几套惊人的业艺。江湖人称无双，意谓天下再没有第
二个学成此等武功之人。
看来他也是听闻此地有江湖失传武功秘笈，专程来此地探宝的。你不
妨向他打听一下有什么收获。
LONG NOR
	 );
	set("title",BLK"武痴"NOR);
	set("nickname",HIW"无双"NOR);
	set("age",32);

	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;


	set_skill("force", t+random(10));
	set_skill("taiji-shengong", t+random(10));
	set_skill("huntian-qigong", t+random(10));
	set_skill("zixia-shengong", t+random(10));

	set_skill("magic", t+random(10));
	set_skill("essencemagic", t+random(10));

	set_skill("dodge", t+random(10));
	set_skill("stormdance", t+random(10));
	set_skill("bat-steps", t+random(10));
	set_skill("baguabu", t+random(10));
	set_skill("tiyunzong", t+random(10));

	set_skill("cuff", t+random(10));
	set_skill("jingang-quan",t+random(10));
	set_skill("taiji-quan", t+random(10));
	set_skill("qishang-quan", t+random(10));
	
	set_skill("claw", t+random(10));
	set_skill("spicyclaw", t+random(10));
	set_skill("sougu", t+random(10));

	set_skill("blade", t+random(10));
	set_skill("shortsong-blade", t+random(10));
	set_skill("spring-blade", t+random(10));

	set_skill("strike", t+random(10));
	set_skill("bloodystrike", t+random(10));
	set_skill("nutrifux", t+random(10));
	set_skill("sanhua-zhang", t+random(10));
	
	set_skill("sword", t+random(10));
	set_skill("dugu-jiujian", t+random(10));
	set_skill("taiji-jian", t+random(10));
	set_skill("six-chaos-sword", t+random(10));



	set_skill("parry", t+random(10));
	set_skill("perception", t+random(10));




//随机初始化功夫map
//首先选择一种内力
	i=random(3);
	if (i==2) 	map_skill("force","taiji-shengong");
	if (i==1) 	map_skill("force","huntian-qigong");
	if (i==0) 	map_skill("force","zixia-shengong");
//魔法只有一种：（
	map_skill("magic", "essencemagic");
//选定一种轻功
	i=random(4);
	if (i==3) 	{map_skill("dodge","stormdance");	map_skill("move","stormdance");}
	if (i==2) 	{map_skill("dodge","bat-steps");	map_skill("move","bat-steps");}
	if (i==1) 	{map_skill("dodge","tiyunzong");	map_skill("move","tiyunzong");}
	if (i==0) 	{map_skill("dodge","baguabu");	map_skill("move","baguabu");}
//选择一种空手功夫
	i=random(8);
//cuff
	if (i==7) 	{map_skill("cuff","jingang-quan");prepare_skill("cuff","jingang-quan");}
	if (i==6) 	{map_skill("cuff","taiji-quan");prepare_skill("cuff","taiji-quan");}
	if (i==5) 	{map_skill("cuff","qishang-quan");prepare_skill("cuff","qishang-quan");}
//claw
	if (i==4) 	{map_skill("claw","spicyclaw");prepare_skill("claw","spicyclaw");}
	if (i==3) 	{map_skill("claw","sougu");prepare_skill("claw","sougu");}
//strike
	if (i==2) 	{map_skill("strike","bloodystrike");prepare_skill("strike","bloodystrike");}
	if (i==1) 	{map_skill("strike","nutrifux");prepare_skill("strike","nutrifux");}
	if (i==0) 	{map_skill("strike","sanhua-zhang");prepare_skill("strike","sanhua-zhang");}
//选择一种兵器
	i=random(3);
	if (i==2) 	map_skill("sword","dugu-jiujian");
	if (i==1) 	map_skill("sword","taiji-jian");
	if (i==0) 	map_skill("sword","six-chaos-sword");
//选择一种招架
	i=random(3);
	if (i==2) 	map_skill("parry","nutrifux");
	if (i==1) 	map_skill("parry","taiji-quan");
	if (i==0) 	map_skill("parry","taiji-jian");
//现在来决定用空手还是用一种兵器
	if (random(100)>50) {
		carry_object("/obj/weapon/sword")->wield();
		set("weapon_type","sword");
	}


	setup();


	carry_object("/obj/cloth/cloth")->wear();

}                          
int killed_enemy(object ob)
{
	command("say 我沉迷武学而习武，杀人非我所愿,你又何苦逼我。");
	command("sigh");
}                 
                     
