#include <ansi.h>
inherit NPC;

string ask_chucun();
string fix_gift();

void create()
{
        object ob;
        set_name("小青年", ({ "yong","qing nian","小青年"}) );
        set("gender", "男性" );
        set("age", 16);
        set("inquiry", ([
               "出村": (: ask_chucun :),
               "天赋": (: fix_gift :),
        ]));
        set("long","一个满脸稚气的小青年，无所事事的站在这儿，如果你想走捷径出村，最好问问他。\n");
        set("combat_exp", 60000);

        carry_object("/obj/cloth")->wear();
        setup();

}
void init()
{
        object ob;
        add_action("do_decide", "decide");
        add_action("do_decide2", "affirm");

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}


void greeting(object ob)
{
                int exp;
        if( !ob || environment(ob) != environment() ) return;
        exp=ob->query("combat_exp");

                if(exp<20000) {
                tell_object(ob,YEL"小青年悄悄对你说道：行走江湖不会武艺可不行哦！你可以用指令"HIW+" skills "NOR+YEL"来查看你现在会的技能。\n"
                +"用"HIW+" help skills "NOR+YEL"可以知道更多关于技能的知识 。\n"NOR);
                tell_object(ob,YEL"小青年悄悄对你说道：迷路了吧？用指令"HIW+" help here "NOR+YEL"可以看到你现在所在地区的地图。\n"NOR);
                }
                if(ob->query("gender")!="女性")
                                return;
                if(ob->query("per")<=20 )
                        {
                                command("sigh "+ob->query("id"));
                                return;
                        }
                        command("kiss "+ob->query("id"));
        return;

}


string ask_chucun()
{
        object me = this_player();

     if( me->query("combat_exp") >49000)
     return "你可以靠自己的本事出村了吧，就别来找我了。";

     command("heihei "+me->query("id"));
     command("grin "+me->query("id"));
     command("goodkid "+me->query("id"));
     command("say 你真的决定要当dummy，一辈子给人做小弟？那我这就送你出去。你可要想好了啊！ \n");
     command("say 如果走捷径出去，你的天赋可能很差，不过我保证你还是会做一个合格的大米的，这点可以放心哦。\n");
     command("say 如果你真的下了决心(decide)，就和我言语一声。\n");
                me->set_temp("ask_chucun",1);
}

int do_decide(string arg)
{
        object me = this_player();
                    
                if ( me->query_temp("ask_chucun",1) ) 
           {
                say("\n小青年低头看了看你，又无奈的摇了摇头，\n\n");
                say("\n说道，既然这样，那好，跟我走吧。\n\n");
                me->set("per",20+random(11));
                me->set("str",20+random(11));
                me->set("int",10);
                me->set("cps",10);
                me->set("cor",10);
                me->set("lea",10);
                me->set("dex",10);
                me->set("bln",10);
                me->set("con",10);
                me->set("kar",10);
                me->set("spi",10);
                me->set("elo",10);
                me->set("msc",10);
                me->set("wil",10);
                me->set("vis",10);

        tell_object(me,HIC"\n小青年偷偷带你到了村口，指给你一条通往雪亭镇的小路，然后飞也般的窜了回去。\n\n"NOR);
        tell_object(me,HIR"你的大米不幸生活开始了！！\n\n"NOR);
                this_player()->set("dummy", 1);
                this_player()->move("/d/snow/crossroad");
         return 1;
           } 
           return;
}


string fix_gift()
{
        object me = this_player();

     if( me->query("fixed_gift"))
     return "我已经帮你调整过一次隐藏天赋了。";

     command("walkby "+me->query("id"));
     command("consider "+me->query("id"));
     command("goodkid "+me->query("id"));
     command("say 如果你真的对自己的隐藏天赋不满意，我倒是可以帮你调整一下。\n");
     command("say 不过别想那么美，我最多给你改成比较好的水平，要想选更好的天赋还是要自己努力的哦。\n");
     command("say 如果你真的做了这个决定(affirm)，就和我言语一声。\n");
                me->set_temp("fix_gift",1);
}

int do_decide2(string arg)
{
        object me = this_player();
                    
                if ( me->query_temp("fix_gift",1) ) 
           {
                tell_object(me,HIC"\n小青年不断的祈祷，“神哪，请赐予这个不幸的孩子重生的力量吧！”\n\n"NOR);
                tell_object(me,HIC"\n接着一道神光照住了你，刹那间你发现自己的资质已经完全变了。\n\n"NOR);
                if (me->query("per") < 20)me->set("per",20);
                if (me->query("kar") < 20)me->set("kar",20);
                if (me->query("spi") < 20)me->set("spi",20);
                if (me->query("elo") < 20)me->set("elo",20);
                if (me->query("msc") < 20)me->set("msc",20);
                if (me->query("wil") < 20)me->set("wil",20);
                if (me->query("vis") < 20)me->set("vis",20);
                if (me->query("fav") < 20)me->set("fav",20);
                me->set("fixed_gift", 1);      
                me->delete_temp("fix_gift", 1);     
                return 1;
           } 
           return;
}



