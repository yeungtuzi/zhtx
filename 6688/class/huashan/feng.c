// feng.c 风清扬

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

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
            set_skill("force",200);
          set_skill("huashan-neigong", 200);
        set_skill("dodge", 200);
        set_skill("huashan-shenfa", 200);
        set_skill("huashan-jianfa", 200);
        set_skill("parry", 200);
        set_skill("sword", 220);
        set_skill("dugu-jiujian",220);
        set_skill("literate", 150);
        set_skill("cuff", 150);
        set_skill("strike", 150);
        set_skill("perception", 150);
        set_skill("dagger", 150);
        set_skill("spear", 150);
        set_skill("blade", 150);
        set_skill("throwing", 150);
        set_skill("whip", 150);
        set_skill("zong-jue",300);
        set_skill("zixia-shengong",200);
        set_skill("purple",200);
        set_skill("wind-sword",200);
        set_skill("yanshuangfei",200);
//        map_skill("literate","zong-jue");
        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "dugu-jiujian");
        map_skill("sword", "dugu-jiujian");
        create_family("华山派剑宗",17,"弟子");
        setup();
        carry_object("/obj/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();
}

void attempt_apprentice(object ob)
{
/*
	变成剑宗气宗都可以学习（原来是华山派）
	加上剑宗201wind-sword和气宗201zixia-force的要求
*/

        string title1;

        if ( !ob->query_temp("marks/风清扬") ) 
        {
                command("say 不历尽千辛万苦, 岂能拜我。");
                return ;
        }

        if (((string)ob->query("family/family_name")!="华山派剑宗")&&((string)ob->query("family/family_name")!="华山派气宗"))
        {
                command("say 你非我派弟子，我不能收你。");
                return ;
        }
	if (((string)ob->query("family/family_name")=="华山派剑宗")&&((int)ob->query_skill("wind-sword", 1) < 201))
	{
		command("say 作为剑宗传人，你不觉得你在剑法上的造诣还不够吗？\n");
		return ;
	}

	if (((string)ob->query("family/family_name")=="华山派气宗")&&((int)ob->query_skill("zixia-shengong", 1) < 201))
	{
		command("say 你还算不上是一个优秀的气宗传人，应该在内功方面再多研究研究。\n");
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

        if ((int)this_player()->query_int() < 50 )
        {
                command("say 学习独孤剑主要要有好的悟性，"+RANK_D->query_respect(ob)+"资质不够。");
                return;
        }

        if ((int)this_player()->query_spi() < 30 )
        {
                command("say 学习独孤剑主要要有好的灵性，"+RANK_D->query_respect(ob)+"资质不够。");
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
	ob->set("family", "华山派剑宗");
        command("recruit "+ob->query("id"));
        ob->set("title", title1);
        
}

