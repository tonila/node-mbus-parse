

#include <nan.h>
#include <mbus.h>

void Method(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

    unsigned char* buffer = (unsigned char*) node::Buffer::Data(info[0]);
    size_t len = node::Buffer::Length(info[0]);
    int normalized = 1;
    unsigned char buf[len];
    mbus_frame reply;
    mbus_frame_data frame_data;
    char *xml_result = NULL, *file = NULL;

    memset(buf, 0, sizeof(buf));
    memcpy(buf, buffer, len);

    memset(&reply, 0, sizeof(reply));
    memset(&frame_data, 0, sizeof(frame_data));
    mbus_parse(&reply, buf, len);
    mbus_frame_data_parse(&reply, &frame_data);
    //mbus_frame_print(&reply);

    xml_result = normalized ? mbus_frame_data_xml_normalized(&frame_data) : mbus_frame_data_xml(&frame_data);

    if (xml_result == NULL)
    {
        char error_msg[] = "Failed to generate XML representation of MBUS frame: %s";
        char* error_str = mbus_error_str();
        char err_buf[sizeof(error_msg) + sizeof(error_str)];
        sprintf(err_buf, error_msg, error_str);
        Nan::ThrowError(err_buf);
        //fprintf(stderr, "Failed to generate XML representation of MBUS frame: %s\n", mbus_error_str());
        return;
    }
    info.GetReturnValue().Set(Nan::New(xml_result).ToLocalChecked());
    free(xml_result);
}

void Init(v8::Local<v8::Object> exports) {
  v8::Local<v8::Context> context = exports->CreationContext();
  exports->Set(context,
      Nan::New("mbus_parse").ToLocalChecked(),
      Nan::New<v8::FunctionTemplate>(Method)
          ->GetFunction(context)
          .ToLocalChecked());
}

NODE_MODULE(mbus, Init)