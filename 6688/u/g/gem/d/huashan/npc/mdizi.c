//jiao_zhong6.c
//by Emote
#include <ansi.h>
inherit NPC;
#include <random_name.h>
void create()
{
        string name,id,nick;

	name = get_rndname();
	id = get_rndid();
	set_name(name, ({ id, "dizi" }) );
	set("gender","男性");
        set("title",HIR "五岳剑派" NOR + "弟子");
 	set("age", 20);
	set("long",
		"这家伙满脸横肉，一付凶神恶煞的模样，令人望而生畏。\n");
	set("combat_exp", 15000+random(15000));
        set("shen_type", 1);
	set("attitude", "heroism");
	
  	set_skill("cuff", 65);
  	set_skill("poyu-quan",70);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("huashan-shenfa",70);
        set_skill("sword",70);
        set_skill("huashan-jianfa",70);
        
        map_skill("dodge","huashan-shenfa");
        map_skill("sword","huashan-jianfa");
        map_skill("parry","huashan-jianfa");
        map_skill("cuff","poyu-quan");
        
        prepare_skill("cuff","poyu-quan");
        setup();
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/cloth")->wear();
}