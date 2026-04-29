// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

void create()
{
        set_name("丰有福", ({ "feng youfu", "feng" , "youfu" }));
        set("title",GRN"粮店老板"NOR);
        set("long",
        "丰记粮店的老板，他有财有势，而且为人和善，经常放义粮，深得四方民众的爱戴。\n");
        set("gender", "男性");
        set("age", 33);
/*       set("vendor_goods",([
         __DIR__"obj/dami.c":20,
         ]));*/
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("combat_exp", 10000);
        set_skill("dodge", 20);
        set_skill("unarmed", 50);
        set_temp("apply/defense", 10);
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
                "丰有福捋着颌下三缕长须说道：如今天下太平，真是百姓有福啊。\n", 
        }) );
    //    carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
        object me;
        ::init();
        add_action("do_vendor_list","list");
        add_action("do_work","work");
        if( interactive(me = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 3, me);
                return;
        }
}
void greeting(object me)
{
        command("say "+RANK_D->query_respect(me)+"想到这儿打工挣钱吗？\n");
}
int do_work()
{
         int qi,luck;
         object me,ob;
         me = this_player();
         luck = random(1000)+1;

         if( me->is_busy() )
         return notify_fail("你正忙着呢，还干什么活啊。\n");

         if( me->query("age") < 18 )
         return notify_fail("丰有福哭丧着脸说：官府现在不准我用小孩子做工了。\n");
         if( me->query("age") > 50 )
         return notify_fail("丰有福斜着瞟了你一眼，“这么大年纪了还不服老啊，还是回家尽享天伦吧”。\n");


         if( me->query("combat_exp") > 800000 )
         return notify_fail("丰有福立即一脸媚态，这位大侠请上座，小的怎敢劳动您的金身大驾。\n");

         qi=me->query("kee");
         if (qi<200) return notify_fail("丰有福说：“想把自己累死么！”\n");
         if( me->query("food")< 40 )
         return notify_fail("你都饿成这样了，还是添饱肚皮再来干活吧。\n");
         if( me->query("water")< 40 )
         return notify_fail("你都渴成这样了，还是喝点水再来干活吧。\n");
         qi=qi-200;
         me->set("kee",qi);
         me->add("food",-20);
         me->add("water",-20);
         me->start_busy(1+random(2));
         message_vision(YEL"$N劳累的干起活来。\n"NOR,me);
         if( luck> 999){
         message_vision(HIC"丰有福看着$N辛劳的背影，不由得怜心大动，\n随即到后面的帐房里取出一张大额的银票用颤抖的手递给了$N。\n"NOR,me);
         ob=new("/obj/money/tenthousand-cash");
         ob->set_amount(random(5)+1);
         ob->move(me);
         }else if( luck > 980 && luck < 1000){
         message_vision(HIG"丰有福看着$N干活这么卖力，乐得连嘴都合不拢了，一高兴就从柜台里取出一叠银票递给了$N。\n"NOR,me);
         ob=new("/obj/money/thousand-cash");
         ob->set_amount(random(3)+1);
         ob->move(me);
         }else if( luck > 900 && luck < 970){
         message_vision(HIY"丰有福美滋滋地看着$N，心想要是人人干活都像$N这样勤奋该有多好，犹豫再三，还是递给$N一大块金锭。\n"NOR,me);
         ob=new("/obj/money/gold");
         ob->set_amount(random(8)+1);
         ob->move(me);
         }else{
         message_vision(HIM"丰有福说：“干的不错，这是工钱。”随手递给$N一块沉甸甸的银锭。\n"NOR,me);
         ob=new("/obj/money/silver");
         ob->set_amount(random(30)+1);
         ob->move(me);
         }
         return 1;

 //        return notify_fail("丰有福说：“干的不错，这是工钱。”\n");
}

void die()
{
        object ob;
        if( objectp(ob = query_temp("last_damage_from")) )
        {
                message("system",  HIM "\n【天杀令】丰有福(Feng Youfu)：" + ob->query("name") + "你这" + RANK_D->query_rude(ob) + "，我受到了天神的特别保护，你居然敢对我放肆，去死吧！\n"NOR,users() );
                ob->set_temp("last_damage_from",this_object());
                ob->die();
        }
        "/cmds/imm/full"->main(this_object(),"");
        revive();
        return;
}


