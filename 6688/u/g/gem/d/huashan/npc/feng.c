// feng.c 风清扬

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_dugu();
void create()
{
        set_name("风清扬",({"feng qingyang","feng"}));
        set("long",
                "华山前辈高人，\n"
                "他今年六十多岁。\n");
        set("nickname", RED "剑魔" NOR);
        set("title",GRN "华山派" NOR + YEL "隐侠" NOR);
        set("gender", "男性");
        set("age", 65);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 60);
        set("int", 150);
        set("no_get",1);
        set("max_kee", 3000);
        set("max_gin", 1500);
        set("force", 8000);
        set("max_force", 4000);
        set("mana", 3000);
        set("max_mana", 3000);
        set("sen", 3000);
        set("max_sen", 3000);
        set("force_factor", 200);
        set("combat_exp", 10000000);
        set("score", 100000);
		  set("skill_mark/dugu-jiujian",1);
        set("inquiry", ([
                "秘诀": (:ask_dugu:),
        ]) );
        set_temp("apply/astral_vision",1);//嘿嘿，用鬼的家伙都去死吧。

		  /*
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "po-qi" :),
		    }) );*/

        set_skill("force",300);
        set_skill("huashan-neigong", 300);
        set_skill("dodge", 300);
        set_skill("yan-shuangfei", 300);
        set_skill("parry", 300);
        set_skill("sword", 300);
        set_skill("dugu-jiujian",300);
        set_skill("literate", 300);
        set_skill("cuff", 300);
        set_skill("poyu-quan", 300);
        set_skill("strike", 300);
        set_skill("perception", 300);
        set_skill("dagger", 300);
        set_skill("spear", 300);
        set_skill("blade", 300);
        set_skill("axe", 300);
        set_skill("throwing", 300);
        set_skill("whip", 300);
        set_skill("hunyuan-zhang", 300);
        set_skill("zong-jue",300);
        map_skill("literate","zong-jue");
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "huashan-neigong");
        map_skill("dodge", "yan-shuangfei");
        map_skill("parry", "dugu-jiujian");
        map_skill("sword", "dugu-jiujian");
        prepare_skill("cuff", "poyu-quan");
        prepare_skill("strike", "hunyuan-zhang");
        create_family("华山派",17,"弟子");
        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();
}

void attempt_apprentice(object ob)
{

        string title1;

        if ( !ob->query_temp("marks/风清扬") ) 
        {
                command("say 不历尽千辛万苦, 岂能拜我。");
                return ;
        }

        if ((string)ob->query("family/family_name")!="华山派") 
        {
                command("say 你非我派弟子，我不能收你。");
                return ;
        }

        if ((string)ob->query("gender")=="无性")
        {
                command("say 我不收无性人。");
                return ;
        }


        if((int)ob->query("betrayer"))
        {
                command("say "+RANK_D->query_respect(ob)+"你多次判师，背信弃义。我怎会收你。\n");
                return;
        }

        if ((int)this_player()->query_int() < 30 )
        {
                command("say 学习独孤剑主要要有好的悟性，"+RANK_D->query_respect(ob)+"资质不够。");
                return;
        }

        if((int)ob->query("shen") < 30000) 
        {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                            "是否还做得不够？");
                return;
        }
        if ((int)ob->query("mud_age") < 250000) {
                command("say 小兄弟虽有向善之心，奈何心志未坚，还是年纪大些再来吧。\n");
                return;
        }
        command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
        command("say 你今后可要惩恶扬善，旷扶正义！绝不可为非作歹，否则为师绝不会放过你的！\n");
        title1=ob->query("title");
        command("recruit "+ob->query("id"));
        ob->set("title", title1);
        
}

int accept_learn(object me, string skill)
{
        if (skill=="dugu-jiujian")
        {
                if (me->query_skill("dugu-jiujian",1)<220)
                        return ::accept_learn(me,skill);
        }
        if (skill=="sword")
        {
                if (me->query_skill("sword",1)<220)
                        return ::accept_learn(me,skill);
        }
        if (skill=="zong-jue")
        {
                if (me->query_skill("zong-jue",1)<200)
                        return ::accept_learn(me,skill);
        }
	   if (skill=="dodge")
        {
                if (me->query_skill("dodge",1)<200)
                        return ::accept_learn(me,skill);
        }
 	   if (skill=="yan-shuangfei")
        {
                if (me->query_skill("yan-shuangfei",1)<200)
                        return ::accept_learn(me,skill);
        }

        if (skill=="blade")
        {
                if (me->query_skill("blade",1)<150)
                        return ::accept_learn(me,skill);
        }
        if (skill=="strike")
        {
                if (me->query_skill("strike",1)<150)
                        return ::accept_learn(me,skill);
        }
        if (skill=="throwing")
        {
                if (me->query_skill("throwing",1)<150)
                        return ::accept_learn(me,skill);
        }
        if (skill=="axe")
        {
                if (me->query_skill("axe",1)<150)
                        return ::accept_learn(me,skill);
        }
        if (skill=="dagger")
        {
                if (me->query_skill("dagger",1)<150)
                        return ::accept_learn(me,skill);
        }
        if (skill=="whip")
        {
                if (me->query_skill("whip",1)<150)
                        return ::accept_learn(me,skill);
        }
        if (skill=="perception")
        {
                if (me->query_skill("perception",1)<180)
                        return ::accept_learn(me,skill);
        }
        if (skill=="spear")
        {
                if (me->query_skill("spear",1)<150)
                        return ::accept_learn(me,skill);
        }
        message_vision("风清扬看了你一眼，想说什么是的，却又欲言而止。\n",me);
        return 0;
        
}

string ask_dugu()
{
	object ppl=this_player();
	if(ppl->query("family/master_name") !="风清扬")
		return "你非我弟子，哪得传我绝学？\n";
	if(ppl->query_skill("dugu-jiujian",1)<220)
	        return "你的剑术修为太差了，学不会的。\n";
	if(ppl->query("faith")<3000)
	        return "你还是先下去，多为本门出些力，为师自然会教你的。\n";
	if(ppl->query("skill_mark/dugu-jiujian"))
		return "你不是已经会了么？还来问我做什么。\n";
	say("风清扬道：“好，我便传你。这独孤九剑我若不传你，过得几年，世上便永远没这\n套剑法了。”说时脸露微笑，显是深以为喜。\n");
	say("风清扬又道：“独孤九剑，重在悟，师傅领进门，修行靠个人，今日我便传你这“\n破气式”的口诀，至于你能领悟几分，就靠你自己了。”\n");
	say("\n说罢，风清扬便传了你口诀和修习之法，说道：“此式是为对付身具上乘内功的敌
人而用，神而明之，存乎一心。独孤前辈当年挟此剑横行天下，欲求一败而不可得
，那是他老人家已将这套剑法使得出神入化之故。同是一门华山剑法，同是一招，
使出来时威力强弱大不相同，这独孤九剑自也一般。你纵然学得了剑法，倘若使出
时剑法不纯，毕竟还是敌不了当世高手，此刻你已得到了门径，要想多胜少败，再
苦练二十年，便可和天下英雄一较长短了。”\n");
	ppl->set("skill_mark/dugu-jiujian",1);
	return "“你这就好生领会去吧。”\n";
}int chat()
{       
        object *enemys,victim;
        int i;
        
        //别太累了
        if( random(100) > 80 || is_busy() ) return ::chat();
        
        clean_up_enemy();
        enemys = query_enemy();
        i = sizeof(enemys);
	    //不和NPC之类的家伙战斗
        while(i--)
        {
                if( !userp(enemys[i]) )
                {
                        remove_enemy(enemys[i]);
                        enemys[i]->remove_enemy(this_object());
                }                                            
        }       
        //现在对手就只剩下玩家了.来判断一下策略
        clean_up_enemy();
        enemys = query_enemy();
        i = sizeof(enemys);
        if( !i ) return ::chat();
        
        //随机挑一个对手吧,选择一个对手，
        victim = enemys[random(i)];     
		  //直接破气，不判断什么兵器了，麻烦死了   	     
		  command("perform po-qi");
        return ::chat();                
        
}   

