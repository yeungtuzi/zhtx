#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
	object sword;

	set_name("厉若海", ({ "li ruohai","li","hai"}) );
	set("long",@LONG
	厉若海是武林第一美男子，一张英俊得绝无瑕疵的脸庞裹，嵌着一双比深黑
海洋里闪闪发光的宝石还明亮的眼睛，冷冷地扫视四方。
LONG
	 );

	set("nickname",RED"邪灵"NOR);
	set("title",BLU"邪异门门主"NOR);
	set("max_gin", 4000);
	set("max_kee", 8000);                    
	set("max_sen", 4000);
	set("max_force",7000); 
	set("force",10000);
	set("force_factor",250);     
	set("combat_exp",69999999);
	set("cor",100);
	set("cps",100);
	set("age",35);
	set("bln",200);
	set("mana",4000);
	set("max_mana",4000);

	set_skill("liaoyuan-spear", 250);
	set_skill("dodge", 250);
	set_skill("mysterrier",250);
	set_skill("parry", 250);
	set_skill("spear",250);
	set_skill("force",300); //防止别人来弹指
	set_skill("liaoyuan-force",250);

	map_skill("force","liaoyuan-force");
	map_skill("spear","liaoyuan-spear");
	map_skill("parry","liaoyuan-spear");
	map_skill("dodge","mysterrier");
	map_skill("move","mysterrier");

	set_temp("apply/damage",150);
/*
	set("chat_chance",3);
        set("chat_msg_combat", ({
		"浪翻云凝视着窗外的明月，姿态悠闲之极。\n",
		"浪翻云举起盛满了清溪流泉的酒壶喝了一大口，笑道：痛快，痛快！\n"
        }) );
*/
	set("chat_chance_combat",10);
        set("chat_msg_combat", ({
		(: exert_function,"flareattack" :),
        }) );

	setup();

	carry_object(__DIR__"obj/lyspear")->wield();
        add_money("tenthousand-cash",1);
            if(random(10)>2) carry_rnd_equip(4,5);
}                          

void init()
{
        set("shen",-500000);
	return 1;
}
                             
int killed_enemy(object ob)
{
	command("sigh");
}

void die()
{
	mapping victims;
	string *vic;
	int i;
	object player;

	victims = query_temp("beat");
	if( !mapp(victims) || !sizeof(victims) ) return ::die();
	vic = keys(victims);
	i = sizeof(vic);
	while(i--)
	{
		if( userp(player=find_player(vic[i])) && present(player,environment()) )
		{
			tell_object(player,"你受到了奖励！你的武林声望提高了！\n");
			player->add("wlshw",1);
		}
	}			
	::die();

}

