//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",6);
	set_name("无忌", ({ "wu ji","wu"}) );
	set("long",GRN@LONG
无忌乃是京城刘宰相的小儿子，出生之时刘宰相请五台山一高僧为
之面相，高僧言道此子不善仕途，却有天资异秉，日后将成旷世之
才。未料此人生性不羁，从小就只爱四处游荡，不愿意久留家中，
刘宰相重金为其聘请的文武高师也一个个被他赶跑或者气跑。六岁
那年他遛到京城附近的鹤翔山去玩，久久未归，京城府派出三百余
人进山找寻无踪，老宰相的妻子大病一场，险些不治。半年后此子
自己回京，品性大改，知礼知节。但不管家人如何询问，只字不谈
半年中到底去了哪儿，是什么人收留了他。十五年后中探花后放弃
做官，行走江湖，世人才惊觉此人竟是用剑高手，而此前无人见其
动过兵器。
LONG NOR
	 );

	set("title",GRN"探花"NOR"剑客");
	set("nickname",WHT"鹤翔一剑"NOR);
	set("age", 23);
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;

	set_skill("pixie-sword", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("force",t+random(10));
	set_skill("stormdance",t+random(10));
	set_skill("kuihua-shengong",t+random(10));
	set_skill("iron-cloth",t+random(10));
	set_skill("jiuyin",t+random(10));
	set_skill("perception", t+random(10));
	set_skill("qiankun-danuoyi", t+random(10));



	map_skill("force","kuihua-shengong");
	map_skill("sword","pixie-sword");
	map_skill("move","stormdance");
	map_skill("dodge","stormdance");
	map_skill("parry","qiankun-danuoyi");
	map_skill("iron-cloth","jiuyin");


	set("chat_chance",3);

	setup();
	set("per",50);
	set_skill("qiankun-danuoyi",230);

	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
	set("weapon_type","sword");
}                          

                             
int killed_enemy(object ob)
{
	command("hmm");
}                 

