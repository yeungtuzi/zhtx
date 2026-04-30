// dunan.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("渡难", ({ "du nan", "nan" }) );
        set("title", HIR "少林" NOR + CYN "长老" NOR);
        set("gender", "男性");
        set("age", 90);
        set("long",
                "这是一个面颊深陷，瘦骨零丁的老僧，他脸色漆黑，象是生铁
铸成。\n");

        set("attitude", "peaceful");
        set("combat_exp", 3000000);
        set("score", 200000);

        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
        set("no_get",1);
        set("kee", 4000);
        set("max_kee", 2000);
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 150);
        set("max_sen",2000);
        set("sen",400);
        set("gin",400);
        set("max_gin",2000);
        create_family("少林派", 35, "弟子");
        assign_apprentice("弟子", 0);

        set_skill("force", 180);
        set_skill("whip", 160);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("finger",180);
        set_skill("strike",180);
        
        set_skill("nianhua-zhi",300);
        set_skill("sanhua-zhang",300);
        
        set_skill("hunyuan-yiqi", 180);
        set_skill("buddhism", 180);
        set_skill("riyue-bian", 200);
        set_skill("shaolin-shenfa", 180);

        map_skill("finger","nianhua-zhi");
        map_skill("strike","sanhua-zhang");
        map_skill("force", "hunyuan-yiqi");
        map_skill("whip",  "riyue-bian");
        map_skill("parry", "riyue-bian");
        map_skill("dodge", "shaolin-shenfa");

        prepare_skill("finger","nianhua-zhi");
        prepare_skill("strike","sanhua-zhang");
        
        set("inquiry", ([
                "菩提子"     : (: ask_me :),
        ]));

//        set("count", random(10)-8);
        set("count", random(2));

        setup();

        carry_object("/d/shaolin/obj/changbian")->wield();
}

void init()
{
        object me, ob;
        mapping fam;

        me = this_player();
        ob = this_object();
        add_action("do_accept","accept");
        ::init();
        if( interactive(me) ) 
        {
                if ( mapp(fam = me->query("family")) && 
fam["family_name"] == "少林派" 
                && fam["generation"] <= 36 ) 
                {
                        me->set_temp("fighter", 1);
                        return;
                }

                if ( mapp(fam = me->query("family")) && 
fam["family_name"] == "少林派" 
                && fam["generation"] > 36               
                && me->query("kee") < 50 ) 
                {
                        me->move("/d/shaolin/qyping");
                        me->unconcious();
                        return;
                }

                if( me->query_temp("fighter") > 2) return;
                COMBAT_D->do_attack(ob, me, query_temp("weapon") );

                me->add_temp("fighter", 1);
                
                ob->fight_ob(me);
                me->fight_ob(ob);

                call_out("halt", 10);

                return;
        }

        return;
}
int do_accept(string arg)
{
        
        if(!this_player()->query_temp("ask_ptz"))
        return 0;
        if(!arg||arg=="")
        return 0;
        if(arg=="no")
          {
                command("sigh");
                command("say 既然这位
"+RANK_D->query_respect(this_player())+"不肯试,那老衲也不能勉强.");
                return 1;
         }
        if(arg=="yes")
        {
                command("say 好,那老衲就得罪了.");
                command("unwield changbian");
                this_player()->set_temp("ask_ptz2",1);
                call_out("do_test",1,this_player());
                return 1;       
        }
        return 0;
}

// 2026-04-30: unused variable commented out
// int do_test(object ppl)
{
        mapping guild;
        object ob,obj;
        remove_call_out("do_test");
//       message_vision("$N kick $n",this_object(),ppl);
        ob =this_object();
	if( query("count") < 1 ){
		 say("渡难说道:我没有菩提子了.\n");
			return 1;
	}

        
if( (ppl->query_temp("ask_ptz")) && (ppl->query_temp("ask_ptz2")) && (ob->query("count")) )
{
                          say("\n渡难突然一声长啸，身形陡然纵起,双手捏法
印,向你攻来.\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        say("渡难叹了口气，说道：连第一招都撑不过，真是
自不量力....\n");
                        return 1;
                }
                say("\n渡难身在空中,居然又是一个转折,回旋到你的身后,又攻
了过来.\n\n");
                   COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        say("渡难「哼」地一声，说道：便是有这许多不怕死
的家伙....\n");
                        return 1;
                }
                say("\n只见渡难在空中身形一浊,翻了个筋斗,头下脚上,运足全
身内力,向你攻出了第三招.\n\n");
                COMBAT_D->do_attack(this_object(), this_player(), 
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        say("渡难叹道：可惜，可惜....\n");
                        return 1;
                }

                say("\n渡难长笑一声:哈哈哈哈,今天我终于找到可以托付的人
了！\n\n");
                obj = new("/d/shaolin/obj/puti-zi");
                 obj->move(this_player());
                add("count", -1);
                command("wield changbian");
                 message_vision("\n渡难惨然一笑，接着长叹一声，从树洞里
取出个白玉磁瓶，倒出菩提子递给$N。\n\n", this_player());
                 say("渡难又长叹一声:我等昔年于佛祖座前发下宏愿，每十年
遍访名山大川，历尽艰险，\n" +
                         "方采得数颗菩提子，君乃有缘人，能得此造化奇物，
望好自为之！");
                
		this_player()->delete_temp("ask_ptz");
	 	return 1;

        }
        return 0;
}
void halt()
{
        command("halt");
}

string ask_me()
{
        mapping fam; 
        object ob;
        
        if ( !this_player()->query_temp("fighter") 
        ||    this_player()->query("combat_exp") < 5000 )
        {
                command("say 大胆鼠辈，乳臭未干，竟敢偷入金刚伏魔圈，且
让老衲来超度与你！");
                this_object()->kill_ob(this_player());
                this_player()->kill_ob(this_object());
        }

        if ( present("puti zi", this_player()) )
                return RANK_D->query_respect(this_player()) + 
                "菩提子只有一颗，而且就在你身上，真是贪得无餍！";

        if ( present("puti zi", environment()) )
                return RANK_D->query_respect(this_player()) + 
                "菩提子只有一颗，而且就在这里任你取走，真是贪得无餍！";


        if (query("count") < 1)
                return "菩提子乃天地之灵物，采集艰难无比，我这里现在可没
有。";
        if(!this_player()->query_temp("pass_du_nan"))
         {
              this_player()->set_temp("ask_ptz",1);
              return "想要菩提子就先接我三招,你可愿意?(accept 
yes/no)\n";
        }

}
