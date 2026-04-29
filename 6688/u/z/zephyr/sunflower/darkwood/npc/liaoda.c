//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",6);
	set_name("廖大", ({ "liao da","liao","da"}) );
	set("long",BLU@LONG
廖大原本是西夏皇帝重金厚礼聘请的一品堂第一高手，因为看不惯赫连铁树的
所作所为，不辞而别，从此不问江湖之事，不知为何居然会在此处见到他。你
虽然诧异，却不敢直接上前去问，因为此人非正非邪，我行我素，素不喜欢别
人对他的事情问东问西。难道他也是来此寻宝？
此时他正眯着眼睛想着什么事情。
LONG NOR
	 );
	set("title",BLU"清风"NOR"隐士");
	set("nickname",HIC"逍遥散人"NOR);
	set("age",32);
	set("skill_mark/spring-blade",1);
	set("percmd","exert powerup");

	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;

	set_skill("blade", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("dodge", t+random(10));

	set_skill("celestial", t+random(10));
	set_skill("celestrike", t+random(10));
	set_skill("spring-blade", t+random(10));
	set_skill("pyrobat-steps", t+random(10));

	map_skill("force", "celestial");
	map_skill("strike","celestrike");
	prepare_skill("strike", "celestrike");
	map_skill("blade", "spring-blade");
	map_skill("dodge", "pyrobat-steps");
	map_skill("move", "pyrobat-steps");



	set("chat_chance",3);

	setup();

	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/blade")->wield();
	set("weapon_type","blade");
}                          

                             
int killed_enemy(object ob)
{
	command("hmm");
}                 
