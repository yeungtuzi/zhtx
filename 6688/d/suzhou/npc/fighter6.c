//NPC:/d/suzhou/npc/fighter6.c 
//by dwolf
//97.11.4
//changed by tlang
         
#include <ansi.h>
#include <combat.h>
inherit NPC;
void consider();

void create()
{
	set_name(BLU"趟子手"NOR, ({ "tangzi shou", "shou", "fighter" }));
	set("age", 28);
	set("gender", "男性");
	set("long", "他是镖局的弟子，武功颇有几分火候。\n");
	set("attitude", "peacefully");

	set("str", 30);
	set("dex", 26);
	set("max_kee",500);
	set("combat_exp", 100000);
	set("shen_type", 1);

	set_skill("unarmed", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("blade", 90);
	set_skill("force", 90);
	set_skill("sword",90);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 50);


        set("chat_chance", 2);
	set("chat_msg", ({
		"这半天来，我觉得又有进步了。\n",
		"师兄，你怎么样？\n",
	}));
	
        set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: consider :),
	}));
	setup();
//	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

void consider()
{
        int i, flag = 0;
        object *enemy;
        object weapon_ob;
        // 2026-04-30: unused variable commented out
        // string ob_pwd,rest;

        enemy = query_enemy() - ({ 0 });
        for(i=0; i<sizeof(enemy); i++) {
                if( !living(enemy[i]) ) continue;
                if( weapon_ob = enemy[i]->query_temp("weapon") ) {
                        flag++;
                        if( !query_temp("weapon") ) {
                                command("say " + RANK_D->query_respect(enemy[i])
 + "既然使兵刃，在下空手接招未免不敬。");
                               // sscanf(sprintf("%O",weapon_ob),"%s#%s",ob_pwd,rest); 
                               // printf("%s\n",ob_pwd);
                                carry_object("/d/suzhou/npc/obj/gangjian")->wield();
                                command("say 进招吧！");
                                break;
                        }
                }
        }
}