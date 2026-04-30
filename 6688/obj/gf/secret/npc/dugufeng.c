
// by yeung
// 1/14/99

#include <ansi.h>

inherit __DIR__"zhanglao";
inherit "/feature/challenge";

void ask_me();
void ask_beg();

void create()
{
        set_name("独孤峰", ({ "dugu feng", "dugu", "feng" }));
        set("title",HIR "日"+HIB"月"+HIY "神教" NOR + "长老");  
        set("nickname",HIB "剑痴神魔"NOR);      
        set("long", @LONG
独孤峰是十大长老之首,东方不败不知所踪之后,日月教日常的事务都由
杨莲亭把持,但是真正最有影响的还是这位长老.只不过他一生献身剑道，
对别的事情很少理会。他神色冷然，脸上从来没有露出过什么笑意。
最近正派中人常常到神教来挑衅生事,一般都由他出面应付.
LONG    
        );
        set("gender", "男性");
        set("age", 51);
        set("attitude", "heroism");
        set("shen_type", -1);
        //想得50万正气,不怕死的就来吧,嘿嘿
        set("shen",-5000000);
        set("cps", 50);
        set("cor", 50);
        set("int", 50);
        
                set("count",1);

        set("max_kee", 5000);
        set("max_gin", 1500);
        set("max_sen", 1500);
        set("force", 8000);
        set("max_force", 4000);
        set("max_atman", 2000);
        set("atman", 2000);
        set("force_factor", 150);
        set("combat_exp", 5000000);
          set("inquiry",([
                "斩铁剑"    : (: ask_me :),
                "借剑"    : (: ask_beg :),
                "求剑"    : (: ask_beg :),
        ]));

        set_skill("perception",180);
        set_skill("force", 180);
        set_skill("tianmo-dafa", 200);
        set_skill("dodge", 180);
        set_skill("mo-shan-jue", 200);
        set_skill("strike", 180);
        set_skill("mo-zhang-jue", 180);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("mo-jian-jue", 200);  
        set_skill("move",180);


        map_skill("force", "tianmo-dafa");
        map_skill("dodge", "mo-shan-jue");
        map_skill("strike", "mo-zhang-jue");
        map_skill("sword","mo-jian-jue");
        map_skill("parry","mo-jian-jue");    
        map_skill("move","mo-shan-jue");
        prepare_skill("strike", "mo-zhang-jue");

        create_family("日月神教", 14, "长老");


        setup();
        carry_object("/d/heimuya/obj/coolsword")->wield();
        suit = new("/obj/cloth");
        suit->move(this_object());
        suitname = query("nickname");
        suit->set("name",suitname+suit_name[random(sizeof(suit_name))]);
        suit->wear();   
//          set("bellicosity",3000);
        set_temp("apply/attack",100);
        set_temp("apply/defense",50);
        set_temp("apply/damage",200);
        set_temp("apply/armor",200);
        set_temp("apply/armor_vs_force",200);   
}

void init()
{
        add_action("do_answer","answer");
        add_action("do_accept","accept");
}
void ask_me()
{
        if (!query("count")) return;
        if (!this_player()->query_temp("weaponor5")) return;
        this_player()->set_temp("ask_me",1);
        set("count",0);
        message_vision(CYN"独孤峰缓缓道斩铁剑是我教震教至宝，你是从何得知？(answer)\n", environment(this_object()));
        return;
}

int do_answer(string arg)
{
        if( !this_player()->query_temp("ask_me") )
                return 0;
        if( !arg ) return notify_fail("你说什么？难道本座是你随意戏弄的吗？快快给我滚了出去。\n"NOR);
        this_player()->delete_temp("ask_me");
        message_vision(CYN"$N向独孤峰解释道：" + arg + "\n", this_player());
        if( strsrch(arg, "江湖百晓生") >=0 ) 
                {
                command("nod");
                command("say 原来是他告诉你的。\n"NOR);
                command("hmm");
                                message_vision(CYN"$N娓娓道来，将斩铁剑的由来和$N为什么来到这里求剑向独孤峰解释一番\n", this_player());
                                message_vision(CYN"独孤峰点点头，说道：原来此剑有如此来历。\n", this_player());
                                message_vision(CYN"几十年来，此剑虽归我教所有，却无一人能够驾驭此剑，原来此乃神物，本不该我等凡人所有的。\n", this_player());
                                command("sigh");
                                this_player()->set_temp("beg_zhantie",1);
        }
           else {
                command("say 你说什么？难道本座是你随意戏弄的吗？快快给我滚了出去。");
        }
        return 1;
}

void ask_beg()
{
        if (!this_player()->query_temp("weaponor5") || !this_player()->query_temp("beg_zhantie")) return;
        message_vision(CYN"独孤峰缓缓道：“好吧，既然此剑非应凡间所有，就与你拿去还给那位高人吧。”\n", environment(this_object()));
        message_vision(CYN"“但是，取剑之前，你需要接我三招，这是本教历来的规矩，承受此剑，必须如此。”\n", environment(this_object()));
        message_vision(CYN"“你可答应？(accept yes/no)。”\n", environment(this_object()));
        this_player()->set_temp("beg_test_accept",1);
        return;
}

int do_accept(string arg)
{
        
        if(!this_player()->query_temp("beg_test_accept"))
        return 0;
        if(!arg||arg=="")
        return 0;
        if(arg=="no")
          {
                command("nod");
                command("say 既然如此这位"+RANK_D->query_respect(this_player())+"请回，老夫不能坏了神教规矩。");
                return 1;
         }
        if(arg=="yes")
        {
                command("say 好,老夫得罪了.");
                this_player()->set_temp("beg_test_accept2",1);
                remove_call_out("do_test");
                call_out("do_test",1);
                return 1;       
        }
        return 0;
}

int do_test()
{
        // 2026-04-30: unused variable commented out
        // mapping guild;
        object player,ob,obj;
        player=this_player();
        ob =this_object();
                ob->add_temp("apply/attack",200);
                ob->add_temp("apply/damage",300);

        if(player->query_temp("beg_test_accept")&&player->query_temp("beg_test_accept2")) {
                          say(CYN"\n独孤峰长啸一声，招式忽然变得精奇异常，手中长剑正如天外飞龙向你飞来。\n\n"NOR);
                COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        say(CYN"独孤峰叹了口气，道：得罪。\n"NOR);
                                                ob->add_temp("apply/attack",-200);
                                                ob->add_temp("apply/damage",-300);

                        return 1;
                }
                say(CYN"\n独孤峰身在空中,头都不回，反转一剑向你刺来。\n\n"NOR);
                   COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        say(CYN"独孤峰说道：得罪了。\n"NOR);
                                                ob->add_temp("apply/attack",-200);
                                                ob->add_temp("apply/damage",-300);
                        return 1;
                }
                say(CYN"\n只见独孤峰双脚一顿，飞身向你跃来，剑锋上透出丝丝青色的光芒，你心里一惊：剑气！\n\n"NOR);
                COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0 
                || !present(this_player(), environment())) {
                        say(CYN"独孤峰叹道：可惜，这已经是第三招了，看来你与此剑无缘了。\n"NOR);
                                                ob->add_temp("apply/attack",-200);
                                                ob->add_temp("apply/damage",-300);
                        return 1;
                }
                                ob->add_temp("apply/attack",-200);
                                ob->add_temp("apply/damage",-300);

                say(CYN"\n独孤峰长笑一声:哈哈哈哈！后生可畏呀！\n\n"NOR);
                command("en");
                command("say 请稍候。");
                                 message_vision(CYN"\n独孤峰转身退进内室，只听得吱吱嘎嘎之声不绝，仿佛正打开什么机关。\n\n", this_player());
                                 message_vision(CYN"\n良久，独孤峰从内室出来，怀中抱着一个黑色的铁匣。\n\n", this_player());
                                 message_vision(CYN"\n独孤峰脸色凝重的把铁匣交给你，说道：这就是斩铁剑了。\n\n", this_player());
                obj = new("/obj/gf/secret/zhantiejian");
                                obj->move(this_player());
                                 this_player()->delete_temp("ask_me");
                                 this_player()->delete_temp("beg_zhantie");
                                 this_player()->delete_temp("beg_test_accept");
                                 this_player()->delete_temp("beg_test_accept2");
                                 return 1;
        }
        return 0;
}





