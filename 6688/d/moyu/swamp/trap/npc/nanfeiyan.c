// master.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("南飞燕", ({ "nan feiyan", "nan", "feiyan" }) );
	set("title",BLU"巫山神女宫宫主"NOR);
	set("nickname",RED"风鬓雨鬓"NOR);
	set("gender", "女性");
	set("age", 44);
	set("attitude", "aggressive");
        set("class", "dancer");

        set("str", 30);
        set("int", 30);
        set("spi", 30);
        set("per", 30);
        set("cor", 50);
        set("cps", 50);
        
        set("force", 5000);
        set("max_force", 10000);
        set("force_factor", 200);
        set("kee",3000);
        set("max_kee",3000);

        set("combat_exp", 12000000);
        set("score", 200000);
        set_temp("apply/armor",200);
        set_temp("apply/armor_vs_force",100);
        set_temp("apply/damage",100);
        set_temp("apply/attack",200);
        set_temp("apply/dodge",100);


        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                "南飞燕身形变幻无形,动作优美,犹如轻歌曼舞。\n",
                (: exert_function, "chillgaze" :),
        }) );
        
        set_skill("finger", 200);
        set_skill("sword", 200);
        set_skill("throwing", 250);
        set_skill("force", 200);
        set_skill("parry", 150);
        set_skill("dodge", 220);
        set_skill("literate", 200);
        set_skill("perception", 150);
        set_skill("whip", 200);
        set_skill("music",100);

        set_skill("stormdance", 180);
        set_skill("tenderzhi", 150);
        set_skill("iceforce", 200);
        set_skill("snowwhip", 200);

        map_skill("dodge", "stormdance");
        map_skill("finger", "tenderzhi");
        prepare_skill("finger","tenderzhi");
        map_skill("force", "iceforce");
        map_skill("whip", "snowwhip");

        
        set_temp("apply/defense", 100);

        setup();

        carry_object(__DIR__"obj/whip")->wield();
}
