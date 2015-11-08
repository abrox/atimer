#ifndef CALLBACK_H
#define CALLBACK_H


class Callback {

   public:

   Callback() :
         type(not_a_callback) {}

   template<class C>
   Callback(C& object, void (C::*method)()) :
         type(from_object),
         object_ptr(reinterpret_cast<generic*>(&object)),
         method_ptr(reinterpret_cast<void (generic::*) ()>(method)) {}

   template<typename T>
   explicit Callback(T function) :
         type(from_function),
         function_ptr((void (*)()) function) {}

   void operator()() {
      switch(type) {
         case from_object:
            (object_ptr ->* method_ptr) ();
            break;
         case from_function:
            function_ptr();
            break;
         default:
          break;
            //throw std::runtime_error("invalid callback");
      };
   }

   private:

   enum { not_a_callback, from_object, from_function } type;

   class generic;

   union {
      void (*function_ptr)();
      struct {
         generic* object_ptr;
         void (generic::*method_ptr)();
      };
   };

};

#endif // CALLBACK_H
