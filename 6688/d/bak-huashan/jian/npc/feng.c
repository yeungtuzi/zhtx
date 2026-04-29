// feng.c 风清扬

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_go();
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
        set("force", 6000);
        set("max_force", 3000);
        set("atman", 3000);
        set("max_atman", 3000);
        set("mana", 3000);
        set("max_mana", 3000);
        set("sen", 1000);
        set("max_sen", 1000);
        set("force_factor", 100);
        set("combat_exp", 10000000);
        set("score", 100000);
        set_skill("force",300);
        set_skill("huashan-neigong", 300);
        set_skill("dodge", 300);
        set_skill("huashan-shenfa", 300);
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
        set_skill("throwing", 300);
        set_skill("whip", 300);
        set_skill("hunyuan-zhang", 300);
        set_skill("zong-jue",300);
        set("inquiry", ([
                "游历" : (: ask_go :),
		"travel" : (: ask_go :),
        ]));
        map_skill("literate","zong-jue");
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "dugu-jiujian");
        map_skill("sword", "dugu-jiujian");
        prepare_skill("cuff", "poyu-quan");
        prepare_skill("strike", "hunyuan-zhang");
        create_family("华山派",17,"弟子");
        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();
}
int ask_go()
{
    object me;
    object ob;
    me=this_player();
    if (me->query("marks/finish_travel"))
    {
      command("say 你已经游历过了，还想出去干什么？\n");
      return 0;	
    }
    if (!(me->query("family/master_name")=="风清扬"))
    {
      command("say 你不是我的徒弟，问我这个干什么？\n");
      command("hmm");
      return 0;    	
    }	
    if (me->query_skill("dugu-jiujian",1)<170)	
    {
       command("say 你的功夫还没学到家，暂时还是不要下山的好。\n");
       return 0;	
    }
    command("say 好吧，你先下山去游历一番，增长点江湖阅历也好。");
    if (!me->query("given_sword"))
    {
      command("say 为师送你一样东西，要好好保管。");
      ob = new(__DIR__"obj/jian");
      ob->move(me);
      tell_object(me,"风清扬递给你一把长剑。\n");
      me->set("given_sword",1);
    }
    me->set("marks/游历",1);
    return 1;
    
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

        if ((int)this_player()->query("int") < 40 )
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
        	if(me->query_skill("dugu-jiujian",1)>170
        	 &&!me->query("save_ren_success"))
        	 {
        	    command("sigh");
        	    command("你既无向善之心,我教了你独孤九剑,不是为江湖又添一个魔头么.\n");
        	    return 0;	
        	 }
                if (me->query_skill("dugu-jiujian",1)<220)
                        return 1;
        }
        if (skill=="sword")
        {
                if (me->query_skill("sword",1)<220)
                        return 1;
        }
        if (skill=="zong-jue")
        {
                if (me->query_skill("zong-jue",1)<200)
                        return 1;
        }
        if (skill=="blade")
        {
                if (me->query_skill("blade",1)<150)
                        return 1;
        }
        if (skill=="strike")
        {
                if (me->query_skill("strike",1)<150)
                        return 1;
        }
        if (skill=="throwing")
        {
                if (me->query_skill("throwing",1)<150)
                        return 1;
        }
        if (skill=="dagger")
        {
                if (me->query_skill("dagger",1)<150)
                        return 1;
        }
        if (skill=="whip")
        {
                if (me->query_skill("whip",1)<150)
                        return 1;
        }
        if (skill=="perception")
        {
                if (me->query_skill("perception",1)<180)
                        return 1;
        }
        if (skill=="spear")
        {
                if (me->query_skill("spear",1)<150)
                        return 1;
        }
        message_vision("风清扬看了你一眼，想说什么是的，却又欲言而止。\n",me);
        return 0;
        
}
