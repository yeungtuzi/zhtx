#include <ansi.h>

inherit "/std/char/doomnpc";

void consider();

void create()
{
        set_name("乔峰", ({"qiao feng", "qiao", "feng"}));

        set("title",MAG "丐帮" NOR + YEL "第十三代" NOR+ MAG "帮主" NOR);
        set("gender", "男性");
        set("age", 35);
        set("long", 
                "他就是和“南慕容”相齐名的“北乔峰”，果然是威风凛凛，\n好一条汉子。他面上颇有风尘之色。");

        set("peaceful",1); //不主动杀人
	set("autoheal",1); //会自行疗伤
	set("leiting",1); //hehe
        
        set("str", 100);
        set("int", 300);
        set("cor", 100);
        set("no_get",1);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :),
                (: exert_function, "powerup" :),
        }) );

        set("kee", 5000);
        set("max_kee", 5000);
        set("gin", 3000);
        set("max_gin", 3000);
        set("sen", 3000);
        set("max_sen", 3000);
        set("atman", 3000);
        set("max_atman",3000);
        set("force", 10000);
        set("max_force", 5000);
        set("mana", 3000);
        set("max_mana", 3000);
        set("force_factor", 300);
        set("combat_exp",5000000);
        set("score", 200000);
        set("shen",1000000);
         
        set_skill("force", 200);             // 基本内功
        set_skill("huntian-qigong", 200);    // 混天气功
        set_skill("strike", 250);
        set_skill("xianglong-zhang", 250);   // 降龙十八掌
        set_skill("dodge", 200);             // 基本躲闪
        set_skill("xiaoyaoyou", 200);        // 逍遥游
        set_skill("parry", 200);             // 基本招架
        set_skill("staff", 250);             // 基本棍杖
        set_skill("dagou-bang", 250);        // 打狗棒法
        
        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("staff", "dagou-bang");

        prepare_skill("strike", "xianglong-zhang");
        
        setup();
		
        if(random(10)>2) carry_rnd_equip(2,4);
	carry_object(__DIR__"obj/yuzhu_zhang");
}

void consider()
{
	if( (query("eff_kee")) < (query("max_kee")*60/100) )
	{
		message_vision(RED"$N怒喝道：居然敢打伤我，老子今天和你拼了！\n"NOR,this_object());
		kill_ob(this_player());
		command("unwield zhang");
		command("perform leiting");
		command("wield zhang");
	}
}

void killed_enemy(object victim)
{
	call_out("do_get",5);
	::killed_enemy(victim);
}

void do_get()
{
	command("get all from corpse");
	command("get corpse");
}
