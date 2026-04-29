//by zephyr

#include <ansi.h>
inherit "/u/z/zephyr/sunflower/npc/advance_npc";
void create()
{
	int lvl,t;
	set("level",5);
	set_name("许一平", ({ "xu yiping","xu"}) );
	set("long",CYN@LONG
许一平原本是天下第一神医，十年前因为不能医治好自己的爱妻的异症，
他将亡妻的身体用药材保护起来，始终不肯下葬，弄得家里下人接连告
辞离开。他本人郁郁寡欢三年零七个月后，撇下苏州偌大的家产，悄然
从江湖消失，同时带走了他的亡妻的身体。
今天居然在此地遇到他，你可以猜想他一定为了找寻传说中起死回生的
轩辕黄经芝来的。
LONG NOR
	 );

	set("title",GRN"百草"NOR"神农");
	set("nickname",BLU"伤心人"NOR);
	set("age", 43);
	set("percmd", "perform dodge.hasten");
	//set advanced skills
	lvl=query("level");
	t=230+(6-lvl)*25;

	set_skill("cuff", t+random(10));
	set_skill("parry", t+random(10));
	set_skill("dodge", t+random(10));
	set_skill("sword", t+random(10));
	set_skill("force", t+random(10));

	set_skill("mystforce", t+random(10));
	set_skill("mystsword", t+random(10));
	set_skill("mysterrier", t+random(10));

	map_skill("sword", "mystsword");
	map_skill("force", "mystforce");
	map_skill("parry", "fonxansword");
	map_skill("dodge", "mysterrier");
	map_skill("move", "mysterrier");

	set("chat_chance",3);
	setup();
	set("per",50);
	carry_object("/obj/cloth/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
	set("weapon_type","sword");
}                          

                             
int killed_enemy(object ob)
{
	command("hmm");
}                 

