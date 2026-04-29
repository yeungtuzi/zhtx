inherit ITEM;

void create()
{
        set_name("内功心法" , ({ "force" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一本介绍基本内功心法的入门书\n");
        set("skill", ([
                "name":                 "force",      
                "exp_required": 30000,       
                "sen_cost":             50,
                "difficulty":   30,  
                "max_skill":    100     
        ]) );
}
      