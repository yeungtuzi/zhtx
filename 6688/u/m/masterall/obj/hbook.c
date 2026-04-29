//stone.c
//by masterall

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"玄天"+HIY"秘笈"NOR , ({ "heaven book", "book" }) );
        set_weight(600);
        set("no_drop",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_paimai",1);
        set("value",0);
        set("long", HIW"这是一册江湖前辈高手们历尽艰辛集毕生所学所写的武功秘笈，但近来由于倭寇猖獗，已然从大内失踪。\n据说研习者只要看上一眼，武功就可以大进，你还不赶快打开(open)看看？\n"NOR);
        if( clonep() )
                set_default_object(__FILE__);   
                set("unit", "册");
        
}
void init()
{
        add_action("open_book","open");
}


int open_book(string arg)
{
       object me,ob;
       int sd,sf,ss,sm,sp,luck;
       me = this_player();
       ob = this_object();

       if( !this_object()->id(arg) ) return 0;

       if( me->query("opened_book") )
                return notify_fail("你对这本秘笈已经完全不感兴趣了。\n");


      
       luck = me->query("kar")/25 + random(2);

       sd = me->query_skill("dodge", 1) + luck;
       sf = me->query_skill("force", 1) + luck;
       ss = me->query_skill("sword", 1) + luck;
       sm = me->query_skill("move", 1) + luck;
       sp = me->query_skill("parry", 1) + luck;
       if ( sd > 400 ) sd = 400;
       if ( sd < 100 ) sd = 100;
       if ( sf > 400 ) sf = 400;
       if ( sf < 100 ) sf = 100;
       if ( ss > 400 ) ss = 400;
       if ( ss < 100 ) ss = 100;
       if ( sm > 400 ) sm = 400;
       if ( sm < 100 ) sm = 100;
       if ( sp > 400 ) sp = 400;
       if ( sp < 100 ) sp = 100;

       


       tell_object(me,HIC"你小心翼翼地打开了这册玄天秘笈，只见上面图文并茂，栩栩如生，\n"NOR);
       tell_object(me,HIW"不但详细记载了吐呐运气之法，还尽录了天下各门各派的剑法，轻功。\n"NOR);
       tell_object(me,HIR"其中精深之处，远比侠客岛石壁上记载得全面而详细。\n"NOR);
       tell_object(me,HIB"小鬼子不通汉语，又不晓中土文化，即便得到此书也无济于事，\n"NOR);
       tell_object(me,HIG"不知不觉间，你已然发现自己的武功造诣陡然提升了一个层次！\n"NOR);
       tell_object(me,HIM"冥冥中你似乎听到有人向你讲道，\n“故天将强大任于斯人也，必先苦其心志，劳其筋骨，饿其体肤，\n空乏其身，行拂乱其所为，所以动心忍性，曾益其所不能。”\n"NOR);
       tell_object(me,HIY"玄天秘笈突然化作一阵清烟，随风飘去了……你呆呆立在那里许久，惊愕得说不出话来。\n"NOR);
       me->set_skill("dodge", sd);
       me->set_skill("force", sf);
       me->set_skill("sword", ss);
       me->set_skill("move", sm);
       me->set_skill("parry", sp);
       me->set("opened_book" ,1);

       destruct(this_object());
        return 1;
}

