inherit F_REPORT;
inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>;
void create()
{
	set_name(HIR"千年虫"NOR,({"qiannian chong","bug","chong"}));
	        set_weight(2000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一条怪异的虫子，看起来五光十色的，却透着股红光，看起来很值钱哦。\n");
                set("value", 10000);
                set("money_id",1);
                set("no_drop",1);
                set("unique_limit",5);
                set("unpawnable",1);
                set("material", "未知属性的元素");
    
        }
        setup();

}

void init()
{       
        object ppl,obj;
       ppl = this_player();
       obj = this_object(); 
       if(ppl == environment(obj))
       {
                remove_call_out("reporting");
                call_out("reporting",1,ppl,obj);
                remove_call_out("count");
                call_out("count",5,ppl);
       }
       add_action("do_conjure","conjure");
       add_action("do_burn","burn");
       add_action("do_go","go");
}

int count(object ppl)
{
     remove_call_out("count");
     remove_call_out("reporting");
     if(environment(ppl)->is_character())
     {
     	tell_object(ppl,"想躲在人身上？没门！\n");
     	remove_call_out("destroying");
     	call_out("destroying",1,this_object());
     	return 1;
     }
     call_out("count",120,ppl);
     
     call_out("reporting",1,ppl,this_object());
     	ppl->add("bugpoint",1);

     if( !( ppl->query("bugpoint") % 30) ) 
		call_out("destroying",1,this_object());
     return 1;
}

int do_conjure()
{
	tell_object(this_player(),"带着虫子，不能使用神通！！\n");
	return 1;
}
int do_burn()
{
	tell_object(this_player(),"带着虫子，不能烧符！！\n");
	return 1;	
}

int do_go() {

	if(random(100) > 50) {
		this_player()->start_busy(random(5));
		return 1;
	}
	else return 0;
}

void destroying(object obj)
{
	tell_object(this_player(),"你觉得胸口一麻，虫子不见了\n");
	destruct(obj);
}
