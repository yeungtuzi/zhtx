// qulingf.c -黄药师

#include <ansi.h>

inherit NPC;
inherit F_MASTER;


void consider();

void create()
{
	set_name(HIM "花　少" NOR , ({ "hua shao", "none"}) );

	set("nickname",  YEL "游戏花间 左右逢源" NOR);
	set("title", GRN "桃花岛副岛主" NOR);
	set("gender", "男性");
	set("age", 56);
	set("long", @LONG
他是东邪黄药师的大弟子,在江湖上闯荡多年,虽然武功不是很
高,但是嫉恶如仇，是江湖上的一位游侠。
随着当初一块闯荡江湖的好友一个个退隐了,他也回到了师傅
身边,协助师傅管理桃花岛。
LONG
	);
	set("attitude", "peaceful");

	set("str", 30);
	set("con", 30);
	set("cor",37);
	set("int", 57);
	set("per", 29);
	set("con",59);
	set("cps",29);

	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("max_kee", 2000);
	set("max_gin", 1000);

	set("combat_exp", 1158602);
	set("shen",1038570);
	set("shen_type",1);
	set("score", 20000);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: consider :)
        }) );
	


        set_skill("force", 180);
	set_skill("taohua-force", 200);
        set_skill("dodge", 190);
        set_skill("baguabu", 180);
        set_skill("strike", 80);
        set_skill("luoying-zhang",100);
        set_skill("hand",100);
        set_skill("lanhua-shou", 100);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("yuxiao-jian", 200);
        set_skill("literate", 170);
        set_skill("qimen-bagua", 80);

        map_skill("force", "taohua-force");
        map_skill("dodge", "baguabu");
        map_skill("hand", "lanhua-shou");
        map_skill("strike","luoying-zhang");
        map_skill("parry", "yuxiao-jian");
        map_skill("sword", "yuxiao-jian");
        
        prepare_skill("hand","lanhua-shou");
        prepare_skill("strike", "luoying-zhang");

        create_family("桃花岛", 2, "大弟子");
        set("class", "平民");

        setup();
	carry_object("/obj/cloth/cloth")->wear();
        carry_object(__DIR__"obj/zxsword")->wield();
}



void attempt_apprentice(object ob)  
{       
         if ((string)this_player()->query("family/family_name")=="桃花岛")
         {if (this_player()->query_skill("qimen-bagua",1)<50)
            { command("say 我门派不传之密奇门八卦,你领悟不够。");
             return;
             }
            else {command("say 好吧，我就代师傅收下你了。");
                 command("recruit " + ob->query("id"));
                 }
          }
         
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        	if((string)ob->query("gender")!="女性")
                {
			ob->set("title",RED "桃花岛" NOR + GRN +"仆人" NOR);
			return;
		}
	        else
                {
			ob->set("title",RED "桃花岛" NOR + GRN +"女仆" NOR);
			return;
		}
       
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        
        command("exert tanzhi " + target->query("id"));
}
