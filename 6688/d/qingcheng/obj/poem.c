inherit ITEM;

void create()
{
        set_name("唐诗三百首" , ({ "poem book","book" }) );
        set_weight(600);
        set("unit", "本");
        set("long", "这是一本平装的很平常的唐诗选辑.\n");
        set("skill", ([
                "name":                 "literate",      
                "exp_required": 5000,       
                     "sen_cost" :    45,
                "difficulty":   10,  
                "max_skill":    50,     
        ]) );
}
      
